#!bin/python3

#Twin primes are a pair of primes that differ by two. For example (3,5),  (5,7),  (11,13) are twin primes. Write a program to display all twin primes less than 1000.

from itertools import cycle

def is_prime(n):
    prime_range = []
    for x in range(1, n + 1):
        if n % x == 0:
            prime_range.append(x)

    if [1, n] == prime_range:
        return True

prime = 1
all_primes = []
while prime < 1000:
    if is_prime(prime):
        all_primes.append(prime)
    prime += 1

lc = cycle(all_primes)
_next = next(lc)
for i in all_primes:
    _this, _next = _next, next(lc)
    if _next - _this == 2:
        print("(", _this, ",", _next, ")")
