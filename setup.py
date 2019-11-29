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
    'packages': ['polyxdr', 'polyxdr/backends', 'polyxdr/backends/xp', 'polyxdr/backends/libproc', 'polyxdr/backends/telem-dict'],
    'package_data': {'polyxdr': ['backends/libproc/templates/*.c', 'backends/libproc/templates/*.h', 'backends/xp/templates/*.xp', 'backends/telem-dict/templates/s*']},
    'scripts': ['poly-xdrgen3']
}

setup(**config)
