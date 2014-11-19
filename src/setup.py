#!/usr/bin/env python2

from setuptools import setup, Extension

validator = Extension(
    'sc._validator',
    sources=[
        'validator/main.c'
    ]
)

modules = [validator]

setup(name='sc',
      packages=['sc'],
      ext_modules=modules,
      test_suite='t',
)
