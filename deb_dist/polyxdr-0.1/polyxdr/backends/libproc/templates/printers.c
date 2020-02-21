void ${st.name.replace('::','_',400)}_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct ${st.name.replace('::','_',400)}), parent, line, level);
}

void ${st.name.replace('::','_',400)}_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &${st.name.replace('::','_',400)}_Struct);
}

void ${st.name.replace('::','_',400)}_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_deallocator((void**)&goner,
         &${st.name.replace('::','_',400)}_Struct);
}

