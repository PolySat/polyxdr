int ${st.name.replace('::','_',400)}_decode(char *src,
      struct ${st.name.replace('::','_',400)} *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, ${st.name.replace('::','_',400)}_Fields);
}

int ${st.name.replace('::','_',400)}_encode(
      struct ${st.name.replace('::','_',400)} *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         ${st.id.replace('::','_',400)} , ${st.name.replace('::','_',400)}_Fields);
}

int ${st.name.replace('::','_',400)}_decode_array(char *src,
      struct ${st.name.replace('::','_',400)} **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct ${st.name.replace('::','_',400)}),
            (XDR_Decoder)&${st.name.replace('::','_',400)}_decode, NULL);

   return 0;
}

int ${st.name.replace('::','_',400)}_encode_array(
      struct ${st.name.replace('::','_',400)} **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct ${st.name.replace('::','_',400)}),
            (XDR_Encoder)&${st.name.replace('::','_',400)}_encode, NULL);

   return 0;
}

int ${st.name.replace('::','_',400)}_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&${st.name.replace('::','_',400)}_decode,
         sizeof(struct ${st.name.replace('::','_',400)}), NULL);
}

int ${st.name.replace('::','_',400)}_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&${st.name.replace('::','_',400)}_encode,
         sizeof(struct ${st.name.replace('::','_',400)}), NULL);
}

void ${st.name.replace('::','_',400)}_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
