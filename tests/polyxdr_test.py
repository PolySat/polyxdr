import unittest
import filecmp
import importlib

from polyxdr.parser import *


class TestPolyxdr(unittest.TestCase):
    def test_xp(self):
        generate_schema_output("xp")
        self.assertTrue(filecmp.cmp("expected/expected.xp", "output/xp.out.xp", shallow=False))

    def test_libproc(self):
        generate_schema_output("libproc")
        self.assertTrue(filecmp.cmp("expected/expected.c", "output/libproc.out.c", shallow=False))
        self.assertTrue(filecmp.cmp("expected/expected.h", "output/libproc.out.h", shallow=False))

#   def test_python(self):
        #generate_schema_output("python")
        #self.assertTrue(filecmp.cmp("expected.python", "schema.python.out", shallow=False))




def generate_schema_output(schema):
    p = Parser(f"{schema}_schema.xp", None)
    with open(f"{schema}_schema.xp", 'r') as f:
        ir = p.xdr_parse(f.read())

    backend = importlib.import_module(f"polyxdr.backends.{schema}")
    backend.generate(ir, f"output/{schema}.out")

if __name__ == "__main__":
    unittest.main()
