struct XDR_TypeFunctions ${bf.name.replace('::','_',400)}_functions = {
   (XDR_Decoder)&${bf.name.replace('::','_',400)}_decode,
   (XDR_Encoder)&${bf.name.replace('::','_',400)}_encode,
   &XDR_print_field_structure, NULL, NULL
};

