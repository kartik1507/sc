#!/usr/bin/env python2

import _validator as lib

def main():
    a = lib.input_wire(1)
    b = lib.input_wire(1)
    for i in xrange(100):
        b = lib.and_gate(a, b)
    print(lib.output_wire(b))

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        pass
