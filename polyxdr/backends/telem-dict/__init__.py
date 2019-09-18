import os
import tenjin
from polyxdr.parser import *
from collections import namedtuple

def generateHeader(ir, output):
   out = open(output, 'w')

#      if isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
   for x in ir:
      if isinstance(x, XDRStruct):
         for m in x.members:
            if m.documentation == None:
               continue

            doc = m.documentation
            print(doc)
            render_template(out, "struct", dict(st=x,doc=doc))

#   for x in ir:
#      if isinstance(x, XDREnum):
#render_template(out, "enum.h", dict(enum=x,types=type_map))
#   for x in ir:
#      if isinstance(x, XDRBitfield):
#         render_template(out, "bitfield.h", dict(st=x,types=type_map))
#   for x in ir:
#      if isinstance(x, XDRStruct):
#         render_template(out, "struct", dict(st=x))
   out.close()

def generate(ir, output):
#    print(ir)
    generateHeader(ir, output)

def render_template(out, name, context):
#print(context)
    path = [os.path.join(os.path.dirname(os.path.realpath(__file__)), 'templates')]
    pp = [ tenjin.PrefixedLinePreprocessor() ] # support "::" syntax
    template_globals = { "to_str": str, "escape": str } # disable HTML escaping
    engine = tenjin.Engine(path=path, pp=pp, cache=tenjin.MemoryCacheStorage())
    out.write(engine.render(name, context, template_globals))
