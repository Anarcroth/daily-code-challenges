#!bin/python3

import itertools

_input = raw_input("Input: ");
_input = _input.split();
_input = list(map(int, _input));

produce_change = _input[0];
my_coins = _input[1:];

_output = raw_input("Output: ");
_output = int(_output);

i = 0;
final_change = 0;
for coin in my_coins:
    final_change += coin;
    i += 1;
    if final_change == produce_change and i <= _output:
        print final_change;

