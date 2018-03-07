#!bin/python3

def is_prime(n):
    prime_range = []
    for x in range(1, n + 1):
        if n % x == 0:
            prime_range.append(x)

    if [1, n] == prime_range:
        return True
count = 1
n = 1
while count < 101:
    if is_prime(n) and is_prime(int(str(n)[::-1])):
        print(count, "- prime: ", n," / emirp: ", int(str(n)[::-1]))
        count += 1
    n += 1
