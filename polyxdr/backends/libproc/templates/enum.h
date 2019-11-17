struct XDR_EnumMapping ${enum.name.replace('::','_',400)} [] = {
:: for m in enum.members:
   { ${str(m.value).replace('::','_',400)}, "${m.name.replace('::','_',400)}" },
:: #endfor
   { 0, NULL }
};

