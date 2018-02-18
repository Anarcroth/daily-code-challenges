#!/bin/python3

import sys

def hackerlandRadioTransmitters(x, k):
    x.sort();
    num_transmitters = 0;
    steps = k * 2 + 1;
    _list = [];
    _list2 = [];
    q = x[0];
    while q <= x[-1]:
        _list2.append(q);
        q += 1;
    i = 0;
    z = 0;
    while i < len(x):
        _list.append([]);
        for n in range(0, steps):
            try:
                print("x[i]: ", x[i], ", x[i + n]: ", x[i + n], ", _list2[i]: ", _list2[i], ", _lsit2[i + n]: ", _list2[i + n]);
            except:
                pass;
            for er in _list2:
                try:
                    if (x[i + n] == _list2[i + n]):
                        _list[z].append(x[i + n]);
                        break;
                except:
                    pass;

           # try:
           #     if (x[i + n] == _list2[i + n]):
           #         _list[z].append(x[i + n]);
           # except:
           #     pass;
        z += 1;
        i += 1;
    print(_list);
    return num_transmitters;

if __name__ == "__main__":
    n, k = input().strip().split(' ')
    n, k = [int(n), int(k)]
    x = list(map(int, input().strip().split(' ')))
    result = hackerlandRadioTransmitters(x, k)
    print(result)
