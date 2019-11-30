void ${st.name.replace('::','_',400)}_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct ${st.name.replace('::','_',400)}), parent, line, level);
}
