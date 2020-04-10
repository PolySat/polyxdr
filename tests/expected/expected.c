#include <stddef.h>
#include "cmd.h"
#include "libproc.out.h"

void IPC_forcelink(void) {}

struct XDR_TypeFunctions IPC_Void_functions = {
   (XDR_Decoder)&IPC_Void_decode,
   (XDR_Encoder)&IPC_Void_encode,
   &XDR_print_field_structure, NULL,
   &IPC_Void_field_deallocator
};

struct XDR_TypeFunctions IPC_Void_arr_functions = {
   (XDR_Decoder)&IPC_Void_decode_array,
   (XDR_Encoder)&IPC_Void_encode_array,
   &IPC_Void_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_Void_dict_functions = {
   (XDR_Decoder)&IPC_Void_decode_dictionary,
   (XDR_Encoder)&IPC_Void_encode_dictionary,
   &IPC_Void_print_dictionary, NULL,
   &IPC_Void_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_Command_functions = {
   (XDR_Decoder)&IPC_Command_decode,
   (XDR_Encoder)&IPC_Command_encode,
   &XDR_print_field_structure, NULL,
   &IPC_Command_field_deallocator
};

struct XDR_TypeFunctions IPC_Command_arr_functions = {
   (XDR_Decoder)&IPC_Command_decode_array,
   (XDR_Encoder)&IPC_Command_encode_array,
   &IPC_Command_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_Command_dict_functions = {
   (XDR_Decoder)&IPC_Command_decode_dictionary,
   (XDR_Encoder)&IPC_Command_encode_dictionary,
   &IPC_Command_print_dictionary, NULL,
   &IPC_Command_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_Heartbeat_functions = {
   (XDR_Decoder)&IPC_Heartbeat_decode,
   (XDR_Encoder)&IPC_Heartbeat_encode,
   &XDR_print_field_structure, NULL,
   &IPC_Heartbeat_field_deallocator
};

struct XDR_TypeFunctions IPC_Heartbeat_arr_functions = {
   (XDR_Decoder)&IPC_Heartbeat_decode_array,
   (XDR_Encoder)&IPC_Heartbeat_encode_array,
   &IPC_Heartbeat_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_Heartbeat_dict_functions = {
   (XDR_Decoder)&IPC_Heartbeat_decode_dictionary,
   (XDR_Encoder)&IPC_Heartbeat_encode_dictionary,
   &IPC_Heartbeat_print_dictionary, NULL,
   &IPC_Heartbeat_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_DataReq_functions = {
   (XDR_Decoder)&IPC_DataReq_decode,
   (XDR_Encoder)&IPC_DataReq_encode,
   &XDR_print_field_structure, NULL,
   &IPC_DataReq_field_deallocator
};

struct XDR_TypeFunctions IPC_DataReq_arr_functions = {
   (XDR_Decoder)&IPC_DataReq_decode_array,
   (XDR_Encoder)&IPC_DataReq_encode_array,
   &IPC_DataReq_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_DataReq_dict_functions = {
   (XDR_Decoder)&IPC_DataReq_decode_dictionary,
   (XDR_Encoder)&IPC_DataReq_encode_dictionary,
   &IPC_DataReq_print_dictionary, NULL,
   &IPC_DataReq_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_OpaqueStruct_functions = {
   (XDR_Decoder)&IPC_OpaqueStruct_decode,
   (XDR_Encoder)&IPC_OpaqueStruct_encode,
   &XDR_print_field_structure, NULL,
   &IPC_OpaqueStruct_field_deallocator
};

struct XDR_TypeFunctions IPC_OpaqueStruct_arr_functions = {
   (XDR_Decoder)&IPC_OpaqueStruct_decode_array,
   (XDR_Encoder)&IPC_OpaqueStruct_encode_array,
   &IPC_OpaqueStruct_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_OpaqueStruct_dict_functions = {
   (XDR_Decoder)&IPC_OpaqueStruct_decode_dictionary,
   (XDR_Encoder)&IPC_OpaqueStruct_encode_dictionary,
   &IPC_OpaqueStruct_print_dictionary, NULL,
   &IPC_OpaqueStruct_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_OpaqueStructArr_functions = {
   (XDR_Decoder)&IPC_OpaqueStructArr_decode,
   (XDR_Encoder)&IPC_OpaqueStructArr_encode,
   &XDR_print_field_structure, NULL,
   &IPC_OpaqueStructArr_field_deallocator
};

struct XDR_TypeFunctions IPC_OpaqueStructArr_arr_functions = {
   (XDR_Decoder)&IPC_OpaqueStructArr_decode_array,
   (XDR_Encoder)&IPC_OpaqueStructArr_encode_array,
   &IPC_OpaqueStructArr_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_OpaqueStructArr_dict_functions = {
   (XDR_Decoder)&IPC_OpaqueStructArr_decode_dictionary,
   (XDR_Encoder)&IPC_OpaqueStructArr_encode_dictionary,
   &IPC_OpaqueStructArr_print_dictionary, NULL,
   &IPC_OpaqueStructArr_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_Response_functions = {
   (XDR_Decoder)&IPC_Response_decode,
   (XDR_Encoder)&IPC_Response_encode,
   &XDR_print_field_structure, NULL,
   &IPC_Response_field_deallocator
};

struct XDR_TypeFunctions IPC_Response_arr_functions = {
   (XDR_Decoder)&IPC_Response_decode_array,
   (XDR_Encoder)&IPC_Response_encode_array,
   &IPC_Response_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_Response_dict_functions = {
   (XDR_Decoder)&IPC_Response_decode_dictionary,
   (XDR_Encoder)&IPC_Response_encode_dictionary,
   &IPC_Response_print_dictionary, NULL,
   &IPC_Response_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_ResponseHeader_functions = {
   (XDR_Decoder)&IPC_ResponseHeader_decode,
   (XDR_Encoder)&IPC_ResponseHeader_encode,
   &XDR_print_field_structure, NULL,
   &IPC_ResponseHeader_field_deallocator
};

struct XDR_TypeFunctions IPC_ResponseHeader_arr_functions = {
   (XDR_Decoder)&IPC_ResponseHeader_decode_array,
   (XDR_Encoder)&IPC_ResponseHeader_encode_array,
   &IPC_ResponseHeader_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_ResponseHeader_dict_functions = {
   (XDR_Decoder)&IPC_ResponseHeader_decode_dictionary,
   (XDR_Encoder)&IPC_ResponseHeader_encode_dictionary,
   &IPC_ResponseHeader_print_dictionary, NULL,
   &IPC_ResponseHeader_dictionary_field_deallocator
};

struct XDR_TypeFunctions IPC_PopulatorError_functions = {
   (XDR_Decoder)&IPC_PopulatorError_decode,
   (XDR_Encoder)&IPC_PopulatorError_encode,
   &XDR_print_field_structure, NULL,
   &IPC_PopulatorError_field_deallocator
};

struct XDR_TypeFunctions IPC_PopulatorError_arr_functions = {
   (XDR_Decoder)&IPC_PopulatorError_decode_array,
   (XDR_Encoder)&IPC_PopulatorError_encode_array,
   &IPC_PopulatorError_print_array, NULL,
   &XDR_struct_array_field_deallocator
};

struct XDR_TypeFunctions IPC_PopulatorError_dict_functions = {
   (XDR_Decoder)&IPC_PopulatorError_decode_dictionary,
   (XDR_Encoder)&IPC_PopulatorError_encode_dictionary,
   &IPC_PopulatorError_print_dictionary, NULL,
   &IPC_PopulatorError_dictionary_field_deallocator
};

static struct XDR_FieldDefinition IPC_Void_Fields[] = {
   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_Void_Struct = {
   IPC_TYPES_VOID, sizeof(struct IPC_Void),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_Void_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_Command_Fields[] = {
   { &xdr_uint32_functions,
      offsetof(struct IPC_Command, cmd),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_functions,
      offsetof(struct IPC_Command, ipcref),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_union_functions,
      offsetof(struct IPC_Command, parameters),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_Command_Struct = {
   IPC_TYPES_COMMAND, sizeof(struct IPC_Command),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_Command_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_Heartbeat_Fields[] = {
   { &xdr_uint64_functions,
      offsetof(struct IPC_Heartbeat, commands),
      "proc_commands", "Commands", NULL,
      NULL,
      NULL,
      0,
      "The number of commands received by the process",
      0 },

   { &xdr_uint64_functions,
      offsetof(struct IPC_Heartbeat, responses),
      "proc_responses", "Responses", NULL,
      NULL,
      NULL,
      0,
      "The number of command responses received by the process",
      0 },

   { &xdr_uint64_functions,
      offsetof(struct IPC_Heartbeat, heartbeats),
      "proc_heartbeats", "Heartbeats", NULL,
      NULL,
      NULL,
      0,
      "The number of heartbeat commands received by the process",
      0 },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_Heartbeat_Struct = {
   IPC_TYPES_HEARTBEAT, sizeof(struct IPC_Heartbeat),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_Heartbeat_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_DataReq_Fields[] = {
   { &xdr_int32_functions,
      offsetof(struct IPC_DataReq, length),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_arr_functions,
      offsetof(struct IPC_DataReq, reqs),
      "types", NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      offsetof(struct IPC_DataReq, length) },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_DataReq_Struct = {
   IPC_TYPES_DATAREQ, sizeof(struct IPC_DataReq),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_DataReq_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_OpaqueStruct_Fields[] = {
   { &xdr_int32_functions,
      offsetof(struct IPC_OpaqueStruct, length),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_byte_arr_functions,
      offsetof(struct IPC_OpaqueStruct, data),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      offsetof(struct IPC_OpaqueStruct, length) },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_OpaqueStruct_Struct = {
   IPC_TYPES_OPAQUE_STRUCT, sizeof(struct IPC_OpaqueStruct),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_OpaqueStruct_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_OpaqueStructArr_Fields[] = {
   { &xdr_int32_functions,
      offsetof(struct IPC_OpaqueStructArr, length),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &IPC_OpaqueStruct_arr_functions,
      offsetof(struct IPC_OpaqueStructArr, structs),
      NULL, NULL, NULL,
      NULL,
      NULL,
      IPC_TYPES_OPAQUE_STRUCT,
      NULL,
      offsetof(struct IPC_OpaqueStructArr, length) },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_OpaqueStructArr_Struct = {
   IPC_TYPES_OPAQUE_STRUCT_ARR, sizeof(struct IPC_OpaqueStructArr),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_OpaqueStructArr_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_Response_Fields[] = {
   { &xdr_uint32_functions,
      offsetof(struct IPC_Response, cmd),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_functions,
      offsetof(struct IPC_Response, ipcref),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_functions,
      offsetof(struct IPC_Response, result),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_union_functions,
      offsetof(struct IPC_Response, data),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_Response_Struct = {
   IPC_TYPES_RESPONSE, sizeof(struct IPC_Response),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_Response_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_ResponseHeader_Fields[] = {
   { &xdr_uint32_functions,
      offsetof(struct IPC_ResponseHeader, cmd),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_functions,
      offsetof(struct IPC_ResponseHeader, ipcref),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_functions,
      offsetof(struct IPC_ResponseHeader, result),
      NULL, NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_ResponseHeader_Struct = {
   IPC_TYPES_RESPONSE_HDR, sizeof(struct IPC_ResponseHeader),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_ResponseHeader_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

static struct XDR_FieldDefinition IPC_PopulatorError_Fields[] = {
   { &xdr_uint32_functions,
      offsetof(struct IPC_PopulatorError, type),
      "struct_type", NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { &xdr_uint32_functions,
      offsetof(struct IPC_PopulatorError, error),
      "error_code", NULL, NULL,
      NULL,
      NULL,
      0,
      NULL,
      0 },

   { NULL, 0, NULL, NULL, NULL, NULL, NULL, 0, NULL, 0 }
};

static struct XDR_StructDefinition IPC_PopulatorError_Struct = {
   IPC_TYPES_POPULATOR_ERROR, sizeof(struct IPC_PopulatorError),
   &XDR_struct_encoder, &XDR_struct_decoder, IPC_PopulatorError_Fields,
   &XDR_malloc_allocator, &XDR_struct_free_deallocator, &XDR_print_fields_func,
   NULL, NULL
};

int IPC_Void_decode(char *src,
      struct IPC_Void *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_Void_Fields);
}

int IPC_Void_encode(
      struct IPC_Void *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_VOID , IPC_Void_Fields);
}

int IPC_Void_decode_array(char *src,
      struct IPC_Void **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Void),
            (XDR_Decoder)&IPC_Void_decode, NULL);

   return 0;
}

int IPC_Void_encode_array(
      struct IPC_Void **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Void),
            (XDR_Encoder)&IPC_Void_encode, NULL);

   return 0;
}

int IPC_Void_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_Void_decode,
         sizeof(struct IPC_Void), NULL);
}

int IPC_Void_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_Void_encode,
         sizeof(struct IPC_Void), NULL);
}

void IPC_Void_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_Command_decode(char *src,
      struct IPC_Command *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_Command_Fields);
}

int IPC_Command_encode(
      struct IPC_Command *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_COMMAND , IPC_Command_Fields);
}

int IPC_Command_decode_array(char *src,
      struct IPC_Command **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Command),
            (XDR_Decoder)&IPC_Command_decode, NULL);

   return 0;
}

int IPC_Command_encode_array(
      struct IPC_Command **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Command),
            (XDR_Encoder)&IPC_Command_encode, NULL);

   return 0;
}

int IPC_Command_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_Command_decode,
         sizeof(struct IPC_Command), NULL);
}

int IPC_Command_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_Command_encode,
         sizeof(struct IPC_Command), NULL);
}

void IPC_Command_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_Heartbeat_decode(char *src,
      struct IPC_Heartbeat *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_Heartbeat_Fields);
}

int IPC_Heartbeat_encode(
      struct IPC_Heartbeat *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_HEARTBEAT , IPC_Heartbeat_Fields);
}

int IPC_Heartbeat_decode_array(char *src,
      struct IPC_Heartbeat **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Heartbeat),
            (XDR_Decoder)&IPC_Heartbeat_decode, NULL);

   return 0;
}

int IPC_Heartbeat_encode_array(
      struct IPC_Heartbeat **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Heartbeat),
            (XDR_Encoder)&IPC_Heartbeat_encode, NULL);

   return 0;
}

int IPC_Heartbeat_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_Heartbeat_decode,
         sizeof(struct IPC_Heartbeat), NULL);
}

int IPC_Heartbeat_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_Heartbeat_encode,
         sizeof(struct IPC_Heartbeat), NULL);
}

void IPC_Heartbeat_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_DataReq_decode(char *src,
      struct IPC_DataReq *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_DataReq_Fields);
}

int IPC_DataReq_encode(
      struct IPC_DataReq *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_DATAREQ , IPC_DataReq_Fields);
}

int IPC_DataReq_decode_array(char *src,
      struct IPC_DataReq **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_DataReq),
            (XDR_Decoder)&IPC_DataReq_decode, NULL);

   return 0;
}

int IPC_DataReq_encode_array(
      struct IPC_DataReq **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_DataReq),
            (XDR_Encoder)&IPC_DataReq_encode, NULL);

   return 0;
}

int IPC_DataReq_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_DataReq_decode,
         sizeof(struct IPC_DataReq), NULL);
}

int IPC_DataReq_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_DataReq_encode,
         sizeof(struct IPC_DataReq), NULL);
}

void IPC_DataReq_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_OpaqueStruct_decode(char *src,
      struct IPC_OpaqueStruct *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_OpaqueStruct_Fields);
}

int IPC_OpaqueStruct_encode(
      struct IPC_OpaqueStruct *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_OPAQUE_STRUCT , IPC_OpaqueStruct_Fields);
}

int IPC_OpaqueStruct_decode_array(char *src,
      struct IPC_OpaqueStruct **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_OpaqueStruct),
            (XDR_Decoder)&IPC_OpaqueStruct_decode, NULL);

   return 0;
}

int IPC_OpaqueStruct_encode_array(
      struct IPC_OpaqueStruct **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_OpaqueStruct),
            (XDR_Encoder)&IPC_OpaqueStruct_encode, NULL);

   return 0;
}

int IPC_OpaqueStruct_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_OpaqueStruct_decode,
         sizeof(struct IPC_OpaqueStruct), NULL);
}

int IPC_OpaqueStruct_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_OpaqueStruct_encode,
         sizeof(struct IPC_OpaqueStruct), NULL);
}

void IPC_OpaqueStruct_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_OpaqueStructArr_decode(char *src,
      struct IPC_OpaqueStructArr *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_OpaqueStructArr_Fields);
}

int IPC_OpaqueStructArr_encode(
      struct IPC_OpaqueStructArr *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_OPAQUE_STRUCT_ARR , IPC_OpaqueStructArr_Fields);
}

int IPC_OpaqueStructArr_decode_array(char *src,
      struct IPC_OpaqueStructArr **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_OpaqueStructArr),
            (XDR_Decoder)&IPC_OpaqueStructArr_decode, NULL);

   return 0;
}

int IPC_OpaqueStructArr_encode_array(
      struct IPC_OpaqueStructArr **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_OpaqueStructArr),
            (XDR_Encoder)&IPC_OpaqueStructArr_encode, NULL);

   return 0;
}

int IPC_OpaqueStructArr_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_OpaqueStructArr_decode,
         sizeof(struct IPC_OpaqueStructArr), NULL);
}

int IPC_OpaqueStructArr_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_OpaqueStructArr_encode,
         sizeof(struct IPC_OpaqueStructArr), NULL);
}

void IPC_OpaqueStructArr_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_Response_decode(char *src,
      struct IPC_Response *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_Response_Fields);
}

int IPC_Response_encode(
      struct IPC_Response *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_RESPONSE , IPC_Response_Fields);
}

int IPC_Response_decode_array(char *src,
      struct IPC_Response **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Response),
            (XDR_Decoder)&IPC_Response_decode, NULL);

   return 0;
}

int IPC_Response_encode_array(
      struct IPC_Response **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_Response),
            (XDR_Encoder)&IPC_Response_encode, NULL);

   return 0;
}

int IPC_Response_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_Response_decode,
         sizeof(struct IPC_Response), NULL);
}

int IPC_Response_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_Response_encode,
         sizeof(struct IPC_Response), NULL);
}

void IPC_Response_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_ResponseHeader_decode(char *src,
      struct IPC_ResponseHeader *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_ResponseHeader_Fields);
}

int IPC_ResponseHeader_encode(
      struct IPC_ResponseHeader *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_RESPONSE_HDR , IPC_ResponseHeader_Fields);
}

int IPC_ResponseHeader_decode_array(char *src,
      struct IPC_ResponseHeader **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_ResponseHeader),
            (XDR_Decoder)&IPC_ResponseHeader_decode, NULL);

   return 0;
}

int IPC_ResponseHeader_encode_array(
      struct IPC_ResponseHeader **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_ResponseHeader),
            (XDR_Encoder)&IPC_ResponseHeader_encode, NULL);

   return 0;
}

int IPC_ResponseHeader_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_ResponseHeader_decode,
         sizeof(struct IPC_ResponseHeader), NULL);
}

int IPC_ResponseHeader_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_ResponseHeader_encode,
         sizeof(struct IPC_ResponseHeader), NULL);
}

void IPC_ResponseHeader_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
int IPC_PopulatorError_decode(char *src,
      struct IPC_PopulatorError *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_decoder(src, dst, used, max, IPC_PopulatorError_Fields);
}

int IPC_PopulatorError_encode(
      struct IPC_PopulatorError *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_struct_encoder(src, dst, used, max,
         IPC_TYPES_POPULATOR_ERROR , IPC_PopulatorError_Fields);
}

int IPC_PopulatorError_decode_array(char *src,
      struct IPC_PopulatorError **dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_decoder(src, (char*)dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_PopulatorError),
            (XDR_Decoder)&IPC_PopulatorError_decode, NULL);

   return 0;
}

int IPC_PopulatorError_encode_array(
      struct IPC_PopulatorError **src, char *dst, size_t *used,
      size_t max, void *len)
{
   *used = 0;
   if (len)
      return XDR_array_encoder((char*)src, dst, used, max, *(int32_t*)len,
            sizeof(struct IPC_PopulatorError),
            (XDR_Encoder)&IPC_PopulatorError_encode, NULL);

   return 0;
}

int IPC_PopulatorError_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_decoder(src, dst, used, max,
         (XDR_Decoder)&IPC_PopulatorError_decode,
         sizeof(struct IPC_PopulatorError), NULL);
}

int IPC_PopulatorError_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len)
{
   return XDR_dictionary_encoder(src, dst, used, max,
         (XDR_Encoder)&IPC_PopulatorError_encode,
         sizeof(struct IPC_PopulatorError), NULL);
}

void IPC_PopulatorError_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_dictionary_field_printer(out, data, field, style,
         len, &XDR_print_field_structure, 0, parent, line, level);
}
void IPC_Void_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_Void), parent, line, level);
}

void IPC_Void_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_Void_Struct);
}

void IPC_Void_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_Void_Struct);
}

void IPC_Command_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_Command), parent, line, level);
}

void IPC_Command_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_Command_Struct);
}

void IPC_Command_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_Command_Struct);
}

void IPC_Heartbeat_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_Heartbeat), parent, line, level);
}

void IPC_Heartbeat_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_Heartbeat_Struct);
}

void IPC_Heartbeat_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_Heartbeat_Struct);
}

void IPC_DataReq_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_DataReq), parent, line, level);
}

void IPC_DataReq_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_DataReq_Struct);
}

void IPC_DataReq_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_DataReq_Struct);
}

void IPC_OpaqueStruct_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_OpaqueStruct), parent, line, level);
}

void IPC_OpaqueStruct_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_OpaqueStruct_Struct);
}

void IPC_OpaqueStruct_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_OpaqueStruct_Struct);
}

void IPC_OpaqueStructArr_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_OpaqueStructArr), parent, line, level);
}

void IPC_OpaqueStructArr_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_OpaqueStructArr_Struct);
}

void IPC_OpaqueStructArr_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_OpaqueStructArr_Struct);
}

void IPC_Response_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_Response), parent, line, level);
}

void IPC_Response_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_Response_Struct);
}

void IPC_Response_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_Response_Struct);
}

void IPC_ResponseHeader_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_ResponseHeader), parent, line, level);
}

void IPC_ResponseHeader_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_ResponseHeader_Struct);
}

void IPC_ResponseHeader_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_ResponseHeader_Struct);
}

void IPC_PopulatorError_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level)
{
   XDR_print_field_structure_array(out, data, field, style, len,
         sizeof(struct IPC_PopulatorError), parent, line, level);
}

void IPC_PopulatorError_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   struct XDR_Dictionary *table = (struct XDR_Dictionary*)goner;

   if (!goner || !field)
      return;
   XDR_dict_remove_all(table, &XDR_dictionary_free_cb,
         &IPC_PopulatorError_Struct);
}

void IPC_PopulatorError_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field)
{
   XDR_struct_free_fields((void**)&goner,
         &IPC_PopulatorError_Struct);
}

static uint32_t IPC_AUTOCMD_3_types[] = {
   IPC_TYPES_HEARTBEAT, 0
};

static struct CMD_XDRCommandInfo IPC_Commands[] = {
   { IPC_CMDS_STATUS, 0,
     "proc-status",
     "Reports the general health status of the test process",
     NULL,
     NULL, NULL, NULL },
   { IPC_CMDS_DATA_REQ, IPC_TYPES_DATAREQ,
     "proc-data-req",
     "Requests a specific set of telemetry items from the processes",
     NULL,
     NULL, NULL, NULL },
   { 0, IPC_TYPES_DATAREQ,
     "proc-heartbeat",
     "Returns process aliveness status information",
     IPC_AUTOCMD_3_types,
     NULL, NULL, NULL },
   { 0, 0, NULL, NULL, NULL, NULL, NULL, NULL }
};

static struct CMD_ErrorInfo IPC_Errors[] = {
   { IPC_RESULTCODE_SUCCESS, "SUCCESS",
     "No error - success" },
   { IPC_RESULTCODE_INCORRECT_PARAMETER_TYPE, "INCORRECT_PARAMETER_TYPE",
     "Type of command parameter didn't match the expected type" },
   { IPC_RESULTCODE_UNSUPPORTED, "UNSUPPORTED",
     "The target process does not support the command sent" },
   { IPC_RESULTCODE_ALLOCATION_ERR, "ALLOCATION_ERR",
     "Failed to allocate heap memory" },
   { 0, NULL, NULL }
};

static void IPC_structs_constructor()
    __attribute__((constructor));

static void IPC_structs_constructor()
{
   XDR_register_struct(&IPC_Void_Struct);
   XDR_register_struct(&IPC_Command_Struct);
   XDR_register_struct(&IPC_Heartbeat_Struct);
   XDR_register_struct(&IPC_DataReq_Struct);
   XDR_register_struct(&IPC_OpaqueStruct_Struct);
   XDR_register_struct(&IPC_OpaqueStructArr_Struct);
   XDR_register_struct(&IPC_Response_Struct);
   XDR_register_struct(&IPC_ResponseHeader_Struct);
   XDR_register_struct(&IPC_PopulatorError_Struct);
   CMD_register_commands(IPC_Commands, 0);
   CMD_register_errors(IPC_Errors);
}
