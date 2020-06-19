:: def nullstr(val, pre, post):
::    if val == None or val == "":
::       return 'NULL'
::    #endif
::    return pre + val + post 
:: #enddef
:: def convstr(div, off, eqn, conv):
::    if div == 1 and off == 0 and eqn == "":
::       return 'NULL'
::    #endif
::    return '&' + conv[str(bits) + ':' + str(off) + ':' + eqn].name
:: #enddef
:: def invstr(div, off, eqn, conv):
::    if div == 1 and off == 0 and eqn == "":
::       return 'NULL'
::    #endif
::    return '&' + conv[eqn + ':' + str(off) + ':' + str(div)].name
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
      ${convstr(m.documentation.divisor, m.documentation.offset, m.documentation.conversion, conv)},
      ${invstr(m.documentation.divisor, m.documentation.offset, m.documentation.inverse, conv)},
      ${bitoffset},
      ${nullstr(m.documentation.description, '"', '"')},
      ${m.bit_length},
      ${nullstr(m.documentation.true_label, '"', '"')},
      ${nullstr(m.documentation.false_label, '"', '"')} },
:: bitoffset += m.bit_length
:: #endfor
   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, NULL, NULL }
};

static struct XDR_StructDefinition ${bf.name.replace('::','_',400)}_Struct = {
   ${bf.id.replace('::','_',400)}, sizeof(struct ${bf.name.replace('::','_',400)}),
   &XDR_bitfield_struct_encoder, &XDR_bitfield_struct_decoder, ${bf.name.replace('::','_',400)}_Fields,
   &XDR_malloc_allocator, &${types[bf.name]['deallocator']}, &XDR_print_fields_func,
   NULL, NULL
};

