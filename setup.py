#!/usr/bin/python3

try:
    from setuptools import setup
except ImportError:
    from distutils.core import setup

config = {
    'name': 'polyxdr',
    'description': 'PolySats custom XDR compiler targeting multiple languages',
    'author': 'PolySat, Rich Lane',
    'url': 'http://github.com/PolySat/libproc',
    'author_email': 'cubesat@cubesat.org',
    'version': '0.1',
    'install_requires': ['nose', 'tenjin', 'pyparsing'],
    'packages': ['polyxdr3', 'polyxdr3/backends', 'polyxdr3/backends/xp', 'polyxdr3/backends/libproc', 'polyxdr3/backends/telem-dict'],
    'package_data': {'polyxdr3': ['backends/libproc/templates/*.c', 'backends/libproc/templates/*.h', 'backends/xp/templates/*.xp', 'backends/telem-dict/templates/s*']},
    'scripts': ['poly-xdrgen3']
}

setup(**config)
