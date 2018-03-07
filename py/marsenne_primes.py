#!bin/python3

#A prime number is called Mersenne prime number if it can be written in the form 2^p-1 for some positive integer p. Write program that finds all Mersenne primes with p <= 31

def is_prime(n):
    prime_range = []
    for x in range(1, n + 1):
        if n % x == 0:
            prime_range.append(x)

    if [1, n] == prime_range:
        return True

p = 1
while p <= 31:
    if is_prime(pow(2, p) - 1):
        print(p, ":", pow(2, p) - 1, "is a Marsenne prime.")
    p += 1
