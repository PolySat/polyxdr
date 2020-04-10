#ifndef LIBPROC_OUT_H
#define LIBPROC_OUT_H

#include "xdr.h"
#include "cmd.h"
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

#define IPC_CMD_BASE (256)

#define IPC_TYPE_BASE (16777472)

#define IPC_ERR_BASE (33554688)

enum IPC_CMDS {
   IPC_CMDS_RESPONSE = IPC_CMD_BASE + 0,
   IPC_CMDS_STATUS = IPC_CMD_BASE + 1,
   IPC_CMDS_DATA_REQ = IPC_CMD_BASE + 2,
};

enum IPC_TYPES {
   IPC_TYPES_VOID = 0,
   IPC_TYPES_OPAQUE_STRUCT = IPC_TYPE_BASE + 1,
   IPC_TYPES_OPAQUE_STRUCT_ARR = IPC_TYPE_BASE + 2,
   IPC_TYPES_COMMAND = IPC_TYPE_BASE + 3,
   IPC_TYPES_RESPONSE = IPC_TYPE_BASE + 4,
   IPC_TYPES_DATAREQ = IPC_TYPE_BASE + 5,
   IPC_TYPES_RESPONSE_HDR = IPC_TYPE_BASE + 6,
   IPC_TYPES_HEARTBEAT = IPC_TYPE_BASE + 7,
   IPC_TYPES_POPULATOR_ERROR = IPC_TYPE_BASE + 8,
};

enum IPC_RESULTCODE {
   IPC_RESULTCODE_SUCCESS = IPC_ERR_BASE + 0,
   IPC_RESULTCODE_INCORRECT_PARAMETER_TYPE = IPC_ERR_BASE + 1,
   IPC_RESULTCODE_UNSUPPORTED = IPC_ERR_BASE + 2,
   IPC_RESULTCODE_ALLOCATION_ERR = IPC_ERR_BASE + 3,
};

enum IPC_VOID_FIELDS {
   IPC_VOID_FIELDS_VOID = 0,
};

struct IPC_Void {
   int voidfield;
};

enum IPC_COMMAND_FIELDS {
   IPC_COMMAND_FIELDS_CMD = 0,
   IPC_COMMAND_FIELDS_IPCREF = 1,
   IPC_COMMAND_FIELDS_PARAMETERS = 2,
};

struct IPC_Command {
   uint32_t cmd;
   uint32_t ipcref;
   struct XDR_Union parameters;
};

enum IPC_HEARTBEAT_FIELDS {
   IPC_HEARTBEAT_FIELDS_COMMANDS = 0,
   IPC_HEARTBEAT_FIELDS_RESPONSES = 1,
   IPC_HEARTBEAT_FIELDS_HEARTBEATS = 2,
};

struct IPC_Heartbeat {
   uint64_t commands;
   uint64_t responses;
   uint64_t heartbeats;
};

enum IPC_DATAREQ_FIELDS {
   IPC_DATAREQ_FIELDS_LENGTH = 0,
   IPC_DATAREQ_FIELDS_REQS = 1,
};

struct IPC_DataReq {
   int32_t length;
   uint32_t *reqs;
};

enum IPC_OPAQUESTRUCT_FIELDS {
   IPC_OPAQUESTRUCT_FIELDS_LENGTH = 0,
   IPC_OPAQUESTRUCT_FIELDS_DATA = 1,
};

struct IPC_OpaqueStruct {
   int32_t length;
   char *data;
};

enum IPC_OPAQUESTRUCTARR_FIELDS {
   IPC_OPAQUESTRUCTARR_FIELDS_LENGTH = 0,
   IPC_OPAQUESTRUCTARR_FIELDS_STRUCTS = 1,
};

struct IPC_OpaqueStructArr {
   int32_t length;
   struct IPC_OpaqueStruct *structs;
};

enum IPC_RESPONSE_FIELDS {
   IPC_RESPONSE_FIELDS_CMD = 0,
   IPC_RESPONSE_FIELDS_IPCREF = 1,
   IPC_RESPONSE_FIELDS_RESULT = 2,
   IPC_RESPONSE_FIELDS_DATA = 3,
};

struct IPC_Response {
   uint32_t cmd;
   uint32_t ipcref;
   uint32_t result;
   struct XDR_Union data;
};

enum IPC_RESPONSEHEADER_FIELDS {
   IPC_RESPONSEHEADER_FIELDS_CMD = 0,
   IPC_RESPONSEHEADER_FIELDS_IPCREF = 1,
   IPC_RESPONSEHEADER_FIELDS_RESULT = 2,
};

struct IPC_ResponseHeader {
   uint32_t cmd;
   uint32_t ipcref;
   uint32_t result;
};

enum IPC_POPULATORERROR_FIELDS {
   IPC_POPULATORERROR_FIELDS_TYPE = 0,
   IPC_POPULATORERROR_FIELDS_ERROR = 1,
};

struct IPC_PopulatorError {
   uint32_t type;
   uint32_t error;
};

extern int IPC_Void_decode(char *src,
      struct IPC_Void *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Void_encode(
      struct IPC_Void *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Void_decode_array(char *src,
      struct IPC_Void **dst, size_t *used,
      size_t max, void *len);
extern int IPC_Void_encode_array(
      struct IPC_Void **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Void_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_Void_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Void_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Void_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_Void_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_Void_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_Command_decode(char *src,
      struct IPC_Command *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Command_encode(
      struct IPC_Command *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Command_decode_array(char *src,
      struct IPC_Command **dst, size_t *used,
      size_t max, void *len);
extern int IPC_Command_encode_array(
      struct IPC_Command **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Command_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_Command_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Command_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Command_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_Command_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_Command_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_Heartbeat_decode(char *src,
      struct IPC_Heartbeat *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Heartbeat_encode(
      struct IPC_Heartbeat *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Heartbeat_decode_array(char *src,
      struct IPC_Heartbeat **dst, size_t *used,
      size_t max, void *len);
extern int IPC_Heartbeat_encode_array(
      struct IPC_Heartbeat **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Heartbeat_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_Heartbeat_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Heartbeat_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Heartbeat_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_Heartbeat_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_Heartbeat_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_DataReq_decode(char *src,
      struct IPC_DataReq *dst, size_t *used,
      size_t max, void *len);
extern int IPC_DataReq_encode(
      struct IPC_DataReq *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_DataReq_decode_array(char *src,
      struct IPC_DataReq **dst, size_t *used,
      size_t max, void *len);
extern int IPC_DataReq_encode_array(
      struct IPC_DataReq **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_DataReq_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_DataReq_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_DataReq_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_DataReq_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_DataReq_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_DataReq_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_OpaqueStruct_decode(char *src,
      struct IPC_OpaqueStruct *dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStruct_encode(
      struct IPC_OpaqueStruct *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStruct_decode_array(char *src,
      struct IPC_OpaqueStruct **dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStruct_encode_array(
      struct IPC_OpaqueStruct **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_OpaqueStruct_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_OpaqueStruct_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStruct_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_OpaqueStruct_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_OpaqueStruct_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_OpaqueStruct_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_OpaqueStructArr_decode(char *src,
      struct IPC_OpaqueStructArr *dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStructArr_encode(
      struct IPC_OpaqueStructArr *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStructArr_decode_array(char *src,
      struct IPC_OpaqueStructArr **dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStructArr_encode_array(
      struct IPC_OpaqueStructArr **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_OpaqueStructArr_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_OpaqueStructArr_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_OpaqueStructArr_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_OpaqueStructArr_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_OpaqueStructArr_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_OpaqueStructArr_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_Response_decode(char *src,
      struct IPC_Response *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Response_encode(
      struct IPC_Response *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Response_decode_array(char *src,
      struct IPC_Response **dst, size_t *used,
      size_t max, void *len);
extern int IPC_Response_encode_array(
      struct IPC_Response **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Response_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_Response_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_Response_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_Response_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_Response_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_Response_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_ResponseHeader_decode(char *src,
      struct IPC_ResponseHeader *dst, size_t *used,
      size_t max, void *len);
extern int IPC_ResponseHeader_encode(
      struct IPC_ResponseHeader *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_ResponseHeader_decode_array(char *src,
      struct IPC_ResponseHeader **dst, size_t *used,
      size_t max, void *len);
extern int IPC_ResponseHeader_encode_array(
      struct IPC_ResponseHeader **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_ResponseHeader_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_ResponseHeader_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_ResponseHeader_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_ResponseHeader_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_ResponseHeader_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_ResponseHeader_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern int IPC_PopulatorError_decode(char *src,
      struct IPC_PopulatorError *dst, size_t *used,
      size_t max, void *len);
extern int IPC_PopulatorError_encode(
      struct IPC_PopulatorError *src, char *dst, size_t *used,
      size_t max, void *len);
extern int IPC_PopulatorError_decode_array(char *src,
      struct IPC_PopulatorError **dst, size_t *used,
      size_t max, void *len);
extern int IPC_PopulatorError_encode_array(
      struct IPC_PopulatorError **src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_PopulatorError_print_array(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern int IPC_PopulatorError_decode_dictionary(char *src,
      struct XDR_Dictionary *dst, size_t *used,
      size_t max, void *len);
extern int IPC_PopulatorError_encode_dictionary(
      struct XDR_Dictionary *src, char *dst, size_t *used,
      size_t max, void *len);
extern void IPC_PopulatorError_print_dictionary(FILE *out, void *data,
      struct XDR_FieldDefinition *field, enum XDR_PRINT_STYLE style,
      const char *parent, void *len, int *line, int level);
extern void IPC_PopulatorError_dictionary_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);
extern void IPC_PopulatorError_field_deallocator(void **goner,
      struct XDR_FieldDefinition *field);

extern void IPC_forcelink(void);

#ifdef __cplusplus
}
#endif

#endif
