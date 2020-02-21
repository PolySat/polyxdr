struct XDR_TypeFunctions ${st.name.replace('::','_',400)}_functions = {
   (XDR_Decoder)&${st.name.replace('::','_',400)}_decode,
   (XDR_Encoder)&${st.name.replace('::','_',400)}_encode,
   &XDR_print_field_structure, NULL,
   &${st.name.replace('::','_',400)}_field_deallocator
};

struct XDR_TypeFunctions ${st.name.replace('::','_',400)}_arr_functions = {
   (XDR_Decoder)&${st.name.replace('::','_',400)}_decode_array,
   (XDR_Encoder)&${st.name.replace('::','_',400)}_encode_array,
   &${st.name.replace('::','_',400)}_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions ${st.name.replace('::','_',400)}_dict_functions = {
   (XDR_Decoder)&${st.name.replace('::','_',400)}_decode_dictionary,
   (XDR_Encoder)&${st.name.replace('::','_',400)}_encode_dictionary,
   &${st.name.replace('::','_',400)}_print_dictionary, NULL,
   &${st.name.replace('::','_',400)}_dictionary_field_deallocator
};

