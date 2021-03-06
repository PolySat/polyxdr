"""
Intermediate Representation (IR)

This file is intended to be imported as "from xdr.ir import *".
"""

from collections import namedtuple

XDRStruct = namedtuple("XDRStruct", ["name", "members", "id"])
XDRDeclaration = namedtuple("XDRDeclaration", ["name", "kind", "type", "length", "length_type", "length_const", "documentation", "bit_length", "type_name"])
XDRBitfield = namedtuple("XDRBitfield", ["name", "id", "members", "type"]);
XDREnum = namedtuple("XDREnum", ["name", "members"])
XDREnumMember = namedtuple("XDREnumMember", ["name", "value"])
XDRConst = namedtuple("XDRConst", ["name", "value"])
XDRTypedef = namedtuple("XDRTypedef", ["declaration"])
XDRUnion = namedtuple("XDRUnion", ["name", "discriminant", "members"])
XDRUnionMember = namedtuple("XDRUnionMember", ["case", "declaration"])
XDRNamespace = namedtuple("XDRNamespace", ["name"])
XDRFieldDocumentation = namedtuple("XDRFieldDocs", ["key", "name", "description", "offset", "divisor", "conversion", "inverse", "unit", "computed_by", "true_label", "false_label"])
XDRCommand = namedtuple("XDRCommand", ["name", "id", "summary", "param", "response", "types", "autoname"])
XDRError = namedtuple("XDRError", ["id", "name", "description"])

__all__ = [
    'XDRStruct', 'XDRDeclaration', 'XDREnum', 'XDREnumMember',
    'XDRConst', 'XDRTypedef', 'XDRUnion', 'XDRUnionMember', 'XDRBitfield',
    'XDRNamespace', 'XDRFieldDocumentation', 'XDRCommand', 'XDRError'
]
