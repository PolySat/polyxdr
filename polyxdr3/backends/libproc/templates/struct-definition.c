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
static struct XDR_FieldDefinition ${st.name.replace('::','_',400)}_Fields[] = {
:: for m in st.members:
::    if m.type == 'void':
::       continue
::    #endif
::    if m.type == 'bitfield':
::       continue
::    #endif
:: if m.length == None:
   { &${types[m.type]['funcs']},
:: else:
   { &${types[m.type]['arr_funcs']},
:: #endif
      offsetof(struct ${st.name.replace('::','_',400)}, ${m.name}),
      ${nullstr(m.documentation.key, '"', '"')}, ${nullstr(m.documentation.name, '"', '"')}, ${nullstr(m.documentation.unit, '"', '"')},
      ${convstr(m.documentation.fractional_bits, m.documentation.conversion, conv)},
      ${invstr(m.documentation.fractional_bits, m.documentation.inverse, conv)},
      ${types[m.type]['id']},
      ${nullstr(m.documentation.description, '"', '"')},
:: if m.length_const:
      0 },
:: else:
      offsetof(struct ${st.name.replace('::','_',400)}, ${m.length}) },
:: #endif

:: #endfor
   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition ${st.name.replace('::','_',400)}_Struct = {
   ${st.id.replace('::','_',400)}, sizeof(struct ${st.name.replace('::','_',400)}),
   &XDR_struct_encoder, &XDR_struct_decoder, ${st.name.replace('::','_',400)}_Fields,
   &XDR_malloc_allocator, &${types[st.name]['deallocator']}, &XDR_print_fields_func,
   NULL, NULL
};

