#!bin/python3

def get_sum_divisors(n):
    return sum(x for x in range(1, n) if n % x == 0)

def isPerfectNumber(n, _sum):
    if _sum == n:
        return True

def isDeficientNumber(n, _sum):
    if _sum < n:
        return True

def isAbundantNumber(n, _sum):
    if _sum > n:
        return True

def isPrimeNumber(n):
    prime_range = []
    for x in range(1, n + 1):
        if n % x == 0:
            prime_range.append(x)

    if [1, n] == prime_range:
        return True

for n in range(1,251):
    _sum = get_sum_divisors(n)

    if isPrimeNumber(n):
        print("The number ", n, " is prime.")
    elif isPerfectNumber(n, _sum):
        print("The number ", n, " is perfect.")
    elif isDeficientNumber(n, _sum):
        print("The number ", n, " is deficient.")
    elif isAbundantNumber(n, _sum):
        print("The number ", n, " is abundant.")
