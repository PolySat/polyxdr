import os
import tenjin
from polyxdr.parser import *
from collections import namedtuple

type_map = { 'int': { 'type': 'int32_t', 'funcs': 'xdr_int32_functions', 'arr_funcs': 'xdr_int32_arr_functions', 'bit_funcs': 'xdr_int32_bitfield_functions', 'dealloc':False, 'id': '0' }, \
             'unsigned int': { 'type': 'uint32_t', 'funcs': 'xdr_uint32_functions', 'arr_funcs': 'xdr_uint32_arr_functions', 'bit_funcs': 'xdr_uint32_bitfield_functions', 'dealloc':False, 'id': '0' }, \
             'bool': { 'type': 'uint32_t', 'funcs': 'xdr_uint32_functions', 'arr_funcs': 'xdr_uint32_arr_functions', 'bit_funcs': 'xdr_uint32_bitfield_functions', 'dealloc':False, 'id': '0' }, \
             'char': { 'type': 'int32_t', 'funcs': 'xdr_char_functions', 'arr_funcs': 'xdr_char_arr_functions', 'dealloc':False, 'id': '0' }, \
             'float': { 'type': 'float', 'funcs': 'xdr_float_functions', 'arr_funcs': 'xdr_float_arr_functions', 'dealloc':False, 'id': '0' }, \
             'double': { 'type': 'double', 'funcs': 'xdr_double_functions', 'arr_funcs': 'xdr_double_arr_functions', 'dealloc':False, 'id': '0' }, \
             'void': { 'type': 'uint32_t', 'funcs': 'xdr_uint32_functions', 'arr_funcs': 'xdr_uint32_arr_functions', 'dealloc':False, 'id': '0' }, \
             'hyper': { 'type': 'int64_t', 'funcs': 'xdr_int64_functions', 'arr_funcs': 'xdr_int64_arr_functions', 'dealloc':False, 'id': '0' }, \
             'unsigned hyper': { 'type': 'uint64_t', 'funcs': 'xdr_uint64_functions', 'arr_funcs': 'xdr_uint64_arr_functions', 'dealloc':False, 'id': '0' }, \
             'string': { 'type': 'const char', 'funcs': 'xdr_string_functions', 'arr_funcs': 'xdr_string_arr_functions', 'dealloc':True, 'deallocator': 'XDR_dealloc_string', 'id': '0' }, \
             'opaque': { 'type': 'char', 'funcs': '', 'arr_funcs': 'xdr_byte_arr_functions', 'dealloc':True, 'deallocator': 'XDR_dealloc_byte', 'id': '0' }, \
           }

def extract_namespace(ir, default, prefix):
   for x in ir:
      if isinstance(x, XDRNamespace):
         if x.name.upper() == prefix:
            return x.name.upper()
         return prefix + '_' + x.name
   return prefix + default

def extract_union_mapping(ir, namespace):
   map = {}
   for x in ir:
      if isinstance(x, XDRUnion) and x.name.split('::')[-1] == 'Data':
         for m in x.members:
            if not m.declaration.type == 'void':
               map[m.declaration.type] = m.case
      if isinstance(x, XDRUnion) and x.name.split('::')[-1] == 'CommandParameters':
         for m in x.members:
            if not m.declaration.type == 'void':
               map[m.declaration.type] = m.case
   return map

def setup_types(ir):
   for x in ir:
      if isinstance(x, XDRUnion):
         type_map[x.name] = { 'type': 'struct XDR_Union', 'funcs': 'xdr_union_functions', 'arr_funcs': 'xdr_union_functions', 'dealloc': True, 'deallocator': 'XDR_dealloc_union', 'id': '0' }
      elif isinstance(x, XDREnum):
         type_map[x.name] = { 'type': 'uint32_t', 'funcs': 'xdr_uint32_functions', 'arr_funcs': 'xdr_uint32_arr_functions', 'bit_funcs': 'xdr_uint32_functions', 'dealloc': False, 'id': '0' }
      elif isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
         dealloc = False;
         deallocator = 'XDR_free_deallocator'
         for m in x.members:
            if isinstance(m, XDRDeclaration):
               dealloc = dealloc or type_map[m.type]['dealloc']
         if dealloc:
            deallocator = x.name.replace('::','_',400) + "_dealloc"
         type_map[x.name] = { 'type': 'struct ' + x.name.replace('::','_',400), 'funcs':  x.name.replace('::','_',400) + "_functions", \
            'arr_funcs':  x.name.replace('::','_',400) + "_arr_functions", \
            'dealloc': dealloc, 'deallocator': 'XDR_struct_free_deallocator', 'id': x.id.replace('::','_',400) }

def generateSource(ir, output, namespace, mapping, conversions):
   out = open(output + ".c", 'w')
   render_template(out, "header.c", dict(namespace=namespace,header=output.split('/')[-1] + ".h"))

   for key, x in conversions.items():
      if x.inverse:
         render_template(out, "inv-conversion.c", dict(conv=x))
      else:
         render_template(out, "fwd-conversion.c", dict(conv=x))

   for x in ir:
      if isinstance(x, XDRBitfield):
         render_template(out, "bitfield-functions.c", dict(bf=x,types=type_map,enums=mapping,conv=conversions))
      if isinstance(x, XDRStruct):
         render_template(out, "struct-functions.c", dict(st=x,types=type_map,enums=mapping,conv=conversions))

   for x in ir:
      if isinstance(x, XDRStruct):
         render_template(out, "struct-definition.c", dict(st=x,types=type_map,enums=mapping,conv=conversions))
      if isinstance(x, XDRBitfield):
         render_template(out, "bitfield-definition.c", dict(bf=x,types=type_map,enums=mapping,conv=conversions))

   for x in ir:
      if isinstance(x, XDRStruct):
         render_template(out, "encoders.c", dict(st=x,types=type_map,enums=mapping))
      if isinstance(x, XDRBitfield):
         render_template(out, "bitfield-encoders.c", dict(st=x,types=type_map,enums=mapping))

   for x in ir:
      if isinstance(x, XDRStruct):
         render_template(out, "printers.c", dict(st=x,types=type_map,enums=mapping))

   for x in ir:
      if isinstance(x, XDRCommand):
         render_template(out, "command-types.c", dict(cmd=x,types=type_map,enums=mapping))
   render_template(out, "command-header.c", dict(ns=namespace))
   for x in ir:
      if isinstance(x, XDRCommand):
         render_template(out, "command-definition.c", dict(cmd=x,types=type_map,enums=mapping))
   render_template(out, "command-footer.c", dict(ns=namespace))

   render_template(out, "error-header.c", dict(ns=namespace))
   for x in ir:
      if isinstance(x, XDRError):
         render_template(out, "error-definition.c", dict(err=x,types=type_map,enums=mapping))
   render_template(out, "error-footer.c", dict(ns=namespace))

   render_template(out, "register.c", dict(namespace=namespace))
   for x in ir:
      if isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
         render_template(out, "register-struct.c", dict(st=x))
   repl = 1;
   if namespace == "IPC":
       repl = 0
   render_template(out, "register-footer.c", dict(namespace=namespace, repl=repl))

   out.close()

def generateHeader(ir, output, namespace, mapping):
   out = open(output + ".h", 'w')
   out.write("#ifndef " + output.split('/')[-1].upper().replace('-','_',400) + "_H\n")
   out.write("#define " + output.split('/')[-1].upper().replace('-','_',400) + "_H\n\n")
   if namespace == 'IPC':
      out.write('#include "xdr.h"\n')
      out.write('#include "cmd.h"\n')
   else:
      out.write("#include <polysat/xdr.h>\n")
      out.write("#include <polysat/cmd.h>\n")
   out.write("#include <stdint.h>\n\n")
   out.write("#ifdef __cplusplus\n")
   out.write('extern "C" {\n')
   out.write("#endif\n\n")


   for x in ir:
      if isinstance(x, XDRConst):
         render_template(out, "const.h", dict(const=x,types=type_map))
   for x in ir:
      if isinstance(x, XDREnum):
         render_template(out, "enum.h", dict(enum=x,types=type_map))
   for x in ir:
      if isinstance(x, XDRBitfield):
         render_template(out, "bitfield.h", dict(st=x,types=type_map))
   for x in ir:
      if isinstance(x, XDRStruct):
         render_template(out, "struct.h", dict(st=x,types=type_map))
   for x in ir:
      if isinstance(x, XDRStruct):
         render_template(out, "prototypes.h", dict(st=x,types=type_map))
   for x in ir:
      if isinstance(x, XDRBitfield):
         render_template(out, "prototypes-bitfield.h", dict(st=x,types=type_map))

   render_template(out, "footer.h", dict(namespace=namespace))
   out.close()

def consolidate_conversions(ir):
   conversions = {}
   number = 0
   Conv = namedtuple("ConversionFunc", ["bits", "equation", "name", "inverse"])
   docs = []
   for x in ir:
      if isinstance(x, XDRStruct) or isinstance(x, XDRBitfield):
         for m in x.members:
            if m.documentation == None:
               continue

            doc = m.documentation
            if doc.fractional_bits > 0 or doc.conversion != '':
               key = str(doc.fractional_bits) + ':' + doc.conversion
               if key not in conversions:
                  conversions[key] = Conv(doc.fractional_bits, doc.conversion, 'unit_conversion_' + str(number), False)
                  number += 1

            if doc.fractional_bits > 0 or doc.inverse != '':
               key = doc.inverse + ':' + str(doc.fractional_bits)
               if key not in conversions:
                  conversions[key] = Conv(doc.fractional_bits, doc.inverse, 'unit_conversion_' + str(number), True)
                  number += 1

   return conversions

def generate(ir, output):
#print(ir)
    namespace = extract_namespace(ir, output, 'IPC')
    mapping = extract_union_mapping(ir, namespace)
    setup_types(ir)
    conversions = consolidate_conversions(ir);
#    for x in type_map:
#       print(x)

    generateHeader(ir, output, namespace, mapping)
    generateSource(ir, output, namespace, mapping, conversions)

def render_template(out, name, context):
#print(context)
    path = [os.path.join(os.path.dirname(os.path.realpath(__file__)), 'templates')]
    pp = [ tenjin.PrefixedLinePreprocessor() ] # support "::" syntax
    template_globals = { "to_str": str, "escape": str } # disable HTML escaping
    engine = tenjin.Engine(path=path, pp=pp, cache=tenjin.MemoryCacheStorage())
    if name == "enum.h":
        print(engine.render(name, context, template_globals))
    out.write(engine.render(name, context, template_globals))
