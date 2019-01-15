:: def nullstr(val, pre, post):
::    if val == None or val == "":
::       return 'NULL'
::    #endif
::    return pre + val + post 
:: #enddef
:: def convstr(bits, eqn, conv):
::    if bits == 0 and eqn == "":
::       return 'NULL'
::    #endif
::    return '&' + conv[str(bits) + ':' + eqn].name
:: #enddef
:: def invstr(bits, eqn, conv):
::    if bits == 0 and eqn == "":
::       return 'NULL'
::    #endif
::    return '&' + conv[eqn + ':' + str(bits)].name
:: #enddef
:: bitoffset = 0
static struct XDR_FieldDefinition ${bf.name.replace('::','_',400)}_Fields[] = {
:: for m in bf.members:
::    if m.type == 'void':
::       continue
::    #endif
   { &${types[m.type]['bit_funcs']},
      offsetof(struct ${bf.name.replace('::','_',400)}, ${m.name}),
      ${nullstr(m.documentation.key, '"', '"')}, ${nullstr(m.documentation.name, '"', '"')}, ${nullstr(m.documentation.unit, '"', '"')},
      ${convstr(m.documentation.fractional_bits, m.documentation.conversion, conv)},
      ${invstr(m.documentation.fractional_bits, m.documentation.inverse, conv)},
      ${bitoffset},
      ${nullstr(m.documentation.description, '"', '"')},
      ${m.bit_length} },
:: bitoffset += m.bit_length
:: #endfor
   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition ${bf.name.replace('::','_',400)}_Struct = {
   ${bf.id.replace('::','_',400)}, sizeof(struct ${bf.name.replace('::','_',400)}),
   &XDR_bitfield_struct_encoder, &XDR_bitfield_struct_decoder, ${bf.name.replace('::','_',400)}_Fields,
   &XDR_malloc_allocator, &${types[bf.name]['deallocator']}, &XDR_print_fields_func,
   NULL, NULL
};

