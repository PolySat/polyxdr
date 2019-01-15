struct ${st.name.replace('::','_',400)} {
:: for m in st.members:
   ${types[m.type_name]['type']} ${m.name};
:: #endfor
};

