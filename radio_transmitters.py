#!/bin/python3

import sys

def hackerlandRadioTransmitters(x, k):
    x.sort();
    num_transmitters = 0;
    step = 1;
    for index, house in enumerate(x[::step]):
        if abs(house - x[index + k - 1]) <= k and abs(x[index + k - 1] - x[index + k*2 - 1]) <= k:
            print("house for transmitter: ", house);
            num_transmitters += 1;
            step = 2*k;
    return num_transmitters;

if __name__ == "__main__":
    n, k = input().strip().split(' ')
    n, k = [int(n), int(k)]
    x = list(map(int, input().strip().split(' ')))
    result = hackerlandRadioTransmitters(x, k)
    print(result)
