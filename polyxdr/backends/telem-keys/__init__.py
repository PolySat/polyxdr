import os
import tenjin
from polyxdr.parser import *
from collections import namedtuple

def generateHeader(ir, out, parent, p_unit, p_name, type_filter):

#      if isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
   for x in ir:
      if isinstance(x, XDRStruct):
#print(x)
         if type_filter != None and x.name != type_filter:
            continue
         for m in x.members:
            if m.documentation == None:
               continue

#print(m.type_name)
            doc = m.documentation
            if not doc.visibility:
               continue
            key = parent
            if parent == None:
               key = doc.key
            else:
               key = parent + '_' + doc.key
            if key == '':
               continue

            render_template(out, "struct", dict(st=x,doc=doc,key=key))
#if "::" in m.type_name:
#               generateHeader(ir, out, key, unit, name, m.type_name)
               

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
    generateHeader(ir, out, None, None, None, None)
    out.close()

def render_template(out, name, context):
#print(context)
    path = [os.path.join(os.path.dirname(os.path.realpath(__file__)), 'templates')]
    pp = [ tenjin.PrefixedLinePreprocessor() ] # support "::" syntax
    template_globals = { "to_str": str, "escape": str } # disable HTML escaping
    engine = tenjin.Engine(path=path, pp=pp, cache=tenjin.MemoryCacheStorage())
    out.write(engine.render(name, context, template_globals))
