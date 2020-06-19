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
::    return '&' + conv[str(div) + ':' + str(off) + ':' + eqn].name
:: #enddef
:: def invstr(div, off, eqn, conv):
::    if div == 1 and off == 0 and eqn == "":
::       return 'NULL'
::    #endif
::    return '&' + conv[eqn + ':' + str(off) + ':' + str(div)].name
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
      ${convstr(m.documentation.divisor, m.documentation.offset, m.documentation.conversion, conv)},
      ${invstr(m.documentation.divisor, m.documentation.offset, m.documentation.inverse, conv)},
      ${types[m.type]['id']},
      ${nullstr(m.documentation.description, '"', '"')},
:: if m.length_const:
      0,
:: else:
      offsetof(struct ${st.name.replace('::','_',400)}, ${m.length}),
:: #endif
      ${nullstr(m.documentation.true_label, '"', '"')},
      ${nullstr(m.documentation.false_label, '"', '"')}, },
:: #endfor
   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0, NULL, NULL }
};

static struct XDR_StructDefinition ${st.name.replace('::','_',400)}_Struct = {
   ${st.id.replace('::','_',400)}, sizeof(struct ${st.name.replace('::','_',400)}),
   &XDR_struct_encoder, &XDR_struct_decoder, ${st.name.replace('::','_',400)}_Fields,
   &XDR_malloc_allocator, &${types[st.name]['deallocator']}, &XDR_print_fields_func,
   NULL, NULL
};

