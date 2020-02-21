extern int ${st.name.replace('::','_',400)}_decode(char *src,
      struct ${st.name.replace('::','_',400)} *dst, size_t *used,
      size_t max, void *len);
extern int ${st.name.replace('::','_',400)}_encode(
      struct ${st.name.replace('::','_',400)} *src, char *dst, size_t *used,
      size_t max, void *len);
extern int ${st.name.replace('::','_',400)}_decode_array(char *src,
      struct ${st.name.replace('::','_',400)} **dst, size_t *used,
      size_t max, void *len);
extern int ${st.name.replace('::','_',400)}_encode_array(
      struct ${st.name.replace('::','_',400)} **src, char *dst, size_t *used,
      size_t max, void *len);
extern void ${st.name.replace('::','_',400)}_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int ${st.name.replace('::','_',400)}_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int ${st.name.replace('::','_',400)}_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void ${st.name.replace('::','_',400)}_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void ${st.name.replace('::','_',400)}_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void ${st.name.replace('::','_',400)}_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

