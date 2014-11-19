#!/usr/bin/env python2

import _validator as lib

S = 0
COUT = 1
ZERO = lib.input_wire(0)
ONE = lib.input_wire(1)
LENGTH = 11

def add(x, y, cin):
    t1 = lib.xor_gate(x, cin);
    t2 = lib.xor_gate(y, cin);
    ret = []
    ret.append(lib.xor_gate(x, t2))
    t1 = lib.and_gate(t1, t2)
    ret.append(lib.xor_gate(cin, t1))
    return ret

def addFull(x, y, cin):
    res = []
    t = add(x[0], y[0], cin)
    res.append(t[S])
    for i in range(len(x) - 1):
        t = add(x[i + 1], y[i + 1], t[COUT])
        res.append(t[S])
    res.append(t[COUT])
    return res

def printWires(x):
    x.reverse();
    for i in range(len(x)):
        print lib.output_wire(x[i]),

def getBinary(a, LENGTH):
    ret = []
    de = []
    for i in range(LENGTH):
        val = a % 2
        a = a/2
        if val == 0:
            ret.append(ZERO)
        else:
            ret.append(ONE)
    return ret
        
    
def main():
    num1 = 500
    num2 = 524
    cin = lib.input_wire(0)
    ret = addFull(getBinary(num1, LENGTH), getBinary(num2, LENGTH), cin)
    printWires(ret)

    #a = lib.input_wire(1)
    #b = lib.input_wire(1)
    #for i in xrange(100):
        #b = lib.and_gate(a, b)
    #print(lib.output_wire(b))

if __name__ == '__main__':
    try:
        main()
    except KeyboardInterrupt:
        pass
