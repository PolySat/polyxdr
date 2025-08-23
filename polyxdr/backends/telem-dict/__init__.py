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

def generateHeader(ir, out, parent, p_unit, p_name, type_filter, p_desc, p_location, p_subsystem, p_divisor, p_offset):

#      if isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
   for x in ir:
      if isinstance(x, XDREvent):
         render_template(out, "event", dict(st=x,proc_name=x.proc_name,port=x.port,id=enumToVal(ir, x.id),desc=x.summary,name=x.name))
      elif isinstance(x, XDRStruct):
#print(x)
         if type_filter != None and x.name != type_filter:
            continue
         for m in x.members:
            has_child = False
            pub_node = True
            pub_child = False
            if "::" in m.type_name:
               has_child = True
               pub_child = True
            doc = m.documentation
            if doc == None:
               continue

            if 0 == doc.visibility:
               continue
            if -1 == doc.visibility and has_child:
               pub_node = False
            if 2 == doc.visibility and (not parent or has_child):
               pub_node = False

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

            desc = p_desc
            if p_desc == None:
               desc = doc.description
            else:
               if doc.description != '':
                  desc = p_desc + '.  ' + doc.description

            location = p_location
            if doc.location and doc.location != '':
               location = doc.location

            subsystem = p_subsystem
            if doc.subsystem and doc.subsystem != '':
               subsystem = doc.subsystem

            divisor = p_divisor
            if not divisor or (doc.divisor != None and doc.divisor != 1):
               divisor = doc.divisor

            offset = p_offset
            if not offset or (doc.offset != None and doc.offset != 0):
               offset = doc.offset
#            print(doc)

            name = p_name
            if p_name == None:
               name = doc.name
            else:
               if doc.name != '':
                  name = p_name + ' - ' + doc.name
            #print(doc)
            if pub_node:
               render_template(out, "struct", dict(st=x,doc=doc,key=key,unit=unit,name=name,desc=desc,location=location,subsystem=subsystem,divisor=divisor,offset=offset))
            if pub_child:
               generateHeader(ir, out, key, unit, name, m.type_name, desc, location, subsystem, divisor, offset)
               

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
    generateHeader(ir, out, None, None, None, None, None, None, None, None, None)
    out.close()

def render_template(out, name, context):
#print(context)
    path = [os.path.join(os.path.dirname(os.path.realpath(__file__)), 'templates')]
    pp = [ tenjin.PrefixedLinePreprocessor() ] # support "::" syntax
    template_globals = { "to_str": str, "escape": str } # disable HTML escaping
    engine = tenjin.Engine(path=path, pp=pp, cache=tenjin.MemoryCacheStorage())
    out.write(engine.render(name, context, template_globals))
