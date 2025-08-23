import os
import tenjin
from polyxdr.parser import *
from collections import namedtuple

def enumToVal(ir, name):
   for x in ir:
      if isinstance(x, XDREnum):
         for m in x.members:
            if m.name == name:
               return m.value
   return "NA"

def resolveStruct(ir, name):
   for x in ir:
      if isinstance(x, XDRStruct):
         if x.name == name:
            return x
   return None

def generate_field(ir, out, subproc, field, parent_key, good_excludes, bad_excludes, p_name, p_location, p_group, parent):
   if field.name in bad_excludes:
      good_excludes.append(field.name)
      bad_excludes.remove(field.name)
      return good_excludes, bad_excludes

   if field.kind != 'basic' or field.type == 'float':
      return good_excludes, bad_excludes
   doc = field.documentation
   if doc is None or doc.visibility == 0:
      return good_excludes, bad_excludes

   pub_node = True
   pub_child = False
   has_child = False
   struct = resolveStruct(ir, field.type_name)
   if struct != None:
      has_child = True
      pub_child = True

   if -1 == doc.visibility and has_child:
      pub_node = False
   if 2 == doc.visibility and (not parent or has_child):
      pub_node = False

   name = p_name
   if field.name != '':
       if name == None or name == '':
          name = field.name
       else:
          name = name + " " + field.name

   location = p_location
   if subproc.location != '':
      location = subproc.location

   group = p_group
   if subproc.group != '':
      group = subproc.group

   if pub_node:
      render_template(out, "subproc-sensor", dict(st=field,doc=doc,name=name,key=parent_key + doc.key,location=location,group=group))

   if pub_child:
      for field in struct.members:
         good_excludes, bad_excludes = generate_field(ir, out, subproc, field, parent_key + doc.key + "_", good_excludes, bad_excludes, name, location, group, struct)

   return good_excludes, bad_excludes

def generate_subproc(ir, out, subproc):
   struct = resolveStruct(ir, subproc.struct)
   if struct is None:
      return

   good_excludes = []
   bad_excludes = subproc.excludes
   render_template(out, "subproc-header", dict(st=subproc,name=subproc.name,path=subproc.path,param=subproc.param))
   for field in struct.members:
      good_excludes, bad_excludes = generate_field(ir, out, subproc, field, "", good_excludes, bad_excludes, None, None, None, None)

   if len(bad_excludes) != 0:
      print("Some excluded fields in datalogger subprocess " + subproc.name +
             "are invalid: " + str(bad_excludes))
   for field in good_excludes:
      render_template(out, "subproc-exclude", dict(key=field))

   render_template(out, "subproc-footer", dict(st=subproc,name=subproc.name,path=subproc.path,param=subproc.param))

def generate(ir, output):
#    print(ir)
    out = open(output, 'w')
    for x in ir:
       if isinstance(x, XDRCommand):
          for subp in x.datalogger:
             generate_subproc(ir, out, subp)
    out.close()

def render_template(out, name, context):
#print(context)
    path = [os.path.join(os.path.dirname(os.path.realpath(__file__)), 'templates')]
    pp = [ tenjin.PrefixedLinePreprocessor() ] # support "::" syntax
    template_globals = { "to_str": str, "escape": str } # disable HTML escaping
    engine = tenjin.Engine(path=path, pp=pp, cache=tenjin.MemoryCacheStorage())
    out.write(engine.render(name, context, template_globals))
