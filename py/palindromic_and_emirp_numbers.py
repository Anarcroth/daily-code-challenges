#!bin/python3

#A palindromic prime is a prime number and also palindromic. 131 is a palindromic prime.

#An emirp (prime spelled backward) is a non palindromic prime number whose reversal is also a prime. For example. 17 is prime and 71 is prime. So 17 and 71 are emirps. Write a program to display the first 100 emirps.

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
