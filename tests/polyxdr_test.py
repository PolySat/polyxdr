import unittest
import filecmp
import importlib

from polyxdr.parser import *


class TestPolyxdr(unittest.TestCase):
    def test_xp(self):
        generate_schema_output("xp")
        self.assertTrue(filecmp.cmp("expected.xp", "schema.xp.out", shallow=False))

    def test_libproc(self):
        generate_schema_output("libproc")
        self.assertTrue(filecmp.cmp("expected.libproc", "schema.libproc.out", shallow=False))

    def test_python(self):
        generate_schema_output("python")
        self.assertTrue(filecmp.cmp("expected.python", "schema.python.out", shallow=False))




def generate_schema_output(schema):
    p = Parser(f"test_schema.{schema}", None)
    with open(f"test_schema.{schema}", 'r') as f:
        ir = p.xdr_parse(f.read())

    backend = importlib.import_module(f"polyxdr.backends.{schema}")
    backend.generate(ir, f"schema.{schema}.out")

if __name__ == "__main__":
    unittest.main()
