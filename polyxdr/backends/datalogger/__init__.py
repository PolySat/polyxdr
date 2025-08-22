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

def generate_subproc(ir, out, subproc):
   struct = resolveStruct(ir, subproc.struct)
   if struct is None:
      return

   good_excludes = []
   bad_excludes = subproc.excludes
   render_template(out, "subproc-header", dict(st=subproc,name=subproc.name,path=subproc.path,param=subproc.param))
   for field in struct.members:
      if field.name in bad_excludes:
         good_excludes.append(field.name)
         bad_excludes.remove(field.name)
         continue

      if field.kind != 'basic' or field.type == 'float':
         continue
      doc = field.documentation
      if doc is None:
         continue
      render_template(out, "subproc-sensor", dict(st=field,doc=doc,name=field.name,key=doc.key,location=subproc.location,group=subproc.group))

   if len(bad_excludes) != 0:
      print("Some excluded fields in datalogger subprocess " + subproc.name +
             "are invalid: " + str(bad_excludes))
   for field in good_excludes:
      render_template(out, "subproc-exclude", dict(key=field))

#      print(field)

   render_template(out, "subproc-footer", dict(st=subproc,name=subproc.name,path=subproc.path,param=subproc.param))

def unused(ir, out):
#      if isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
   for x in ir:
      if isinstance(x, XDREvent):
         render_template(out, "event", dict(st=x,proc_name=x.proc_name,port=x.port,id=enumToVal(ir, x.id),desc=x.summary,name=x.name))
      elif isinstance(x, XDRStruct):
#print(x)
         if type_filter != None and x.name != type_filter:
            continue
         for m in x.members:
            if m.documentation == None:
               continue

#print(m.type_name)
            doc = m.documentation
            if not doc.export:
               continue
            key = parent
            if parent == None:
               key = doc.key
            else:
               key = parent + '_' + doc.key
            if key == '':
               continue

            unit = p_unit
            if p_unit == None or doc.unit != '':
               unit = doc.unit

            name = p_name
            if p_name == None:
               name = doc.name
            else:
               if doc.name != '':
                  name = p_name + ': ' + doc.name
            #print(doc)
            render_template(out, "struct", dict(st=x,doc=doc,key=key,unit=unit,name=name))
            if "::" in m.type_name:
               generateHeader(ir, out, key, unit, name, m.type_name)
               

#   for x in ir:
#      if isinstance(x, XDREnum):
#render_template(out, "enum.h", dict(enum=x,types=type_map))
#   for x in ir:
#      if isinstance(x, XDRBitfield):
#         render_template(out, "bitfield.h", dict(st=x,types=type_map))
#   for x in ir:
#      if isinstance(x, XDRStruct):
#         render_template(out, "struct", dict(st=x))

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
