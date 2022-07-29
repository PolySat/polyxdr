enum ${st.name.replace('::','_',400).upper()}_FIELDS {
:: for idx, m in enumerate(st.members):
::    if m.type == 'void':
   ${st.name.replace('::','_',400).upper()}_FIELDS_VOID = ${idx},
::    else:
   ${st.name.replace('::','_',400).upper()}_FIELDS_${m.name.upper()} = ${idx},
::    #endif
:: #endfor
};

struct ${st.name.replace('::','_',400)} {
:: for m in st.members:
::    if m.type == 'void':
   int voidfield;
::       continue
::    #endif
::    if m.type == 'bitfield':
   int bitfield;
::       continue
::    #endif
:: if (m.kind == 'array' or m.kind == 'list') and m.length_type == 'fixed':
   ${types[m.type_name]['type']} ${m.name}[${m.length}];
:: elif m.kind == 'array' or m.kind == 'list':
   ${types[m.type_name]['type']} *${m.name};
:: else:
   ${types[m.type_name]['type']} ${m.name};
:: #endif
:: #endfor
};

