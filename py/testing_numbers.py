#!bin/python3

#A number is said to be perfect if the sum of its divisors (except for itself) is equal to itself. Example: 6 is perfect as sum of its divisors ( 1 + 2 + 3 ) = 6.
#You need a method:	boolean isPerfectNumber(int n) {  …  }
#
#A number is said to be deficient if the sum of its divisors (except for itself) is less than the number itself. Example: 8 is deficient because sum of its divisors ( 1 + 2 + 4 ) = 7 < 8.
#You need a method:	boolean isDeficientNumber(int n) {  …  }
#
#A number is said to be abundant if the sum of its divisors (except for itself) is greater than the number itself. Example: 12 is abundant because sum of its divisors (1+2+3+4+6)=16>12.
#You need a method:	boolean isAbundantNumber(int n) {  …  }
#
#Any number that’s divisible only by one and itself is said to be prime.
#You need a method:	boolean isPrimeNumber(int n) {  …  }
#
#Write program to display all perfect, deficient, abundant, prime numbers in the range 1 .. 250.

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
