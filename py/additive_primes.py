#!bin/python3

def is_prime(n):
    prime_range = []
    for x in range(1, n + 1):
        if n % x == 0:
            prime_range.append(x)

    if [1, n] == prime_range:
        return True

i = 1
n = 1
while i < 26:
    if is_prime(n):
        _sum = 0
        for x in str(n):
            _sum += int(x)
        if is_prime(_sum):
            print(i, ":", n, " is an additive prime")
            i += 1
    n += 1
