#!bin/python3

#Background
#
#Consider all the different ways of representing a positive integer using nothing but positive integers, addition, multiplication, and parentheses. For 5678, a few such ways are:
#
#5678 = 2*17*167
#5678 = 5678
#5678 = 23*59+29*149
#5678 = (1+4*4)*(1+3*3*(1+3*3*4))
#5678 = 2*(1+2*(1+2*(1+2*2*(1+2*2*2*2*(1+2*(1+2*2))))))
#
#For each such representation, consider the sum of the integers involved:
#
#2*17*167 => 2+17+167 = 186
#5678 => 5678 = 5678
#23*59+29*149 => 23+59+29+149 = 260
#(1+4*4)*(1+3*3*(1+3*3*4)) => 1+4+4+1+3+3+1+3+3+4 = 27
#2*(1+2*(1+2*(1+2*2*(1+2*2*2*2*(1+2*(1+2*2)))))) =>
#    2+1+2+1+2+1+2+2+1+2+2+2+2+1+2+1+2+2 = 30
#
#For 5678, the minimum possible sum for any such representation is 27. The minimum possible sum for a given integer is known as its integer complexity, so the integer complexity of 5678 is 27. The integer complexity of the numbers 1, 2, 3, ... is:
#
#1 2 3 4 5 5 6 6 6 7 8 7 8 8 8 8 9 8 9 9 ...
#
#The sum of the integer complexities for all numbers from 1 to 100 inclusive is 1113.
#Challenge
#
#Find the sum of the integer complexities for all numbers from 1 to 1000, inclusive.
#
#It's not sufficient to write a program that will eventually get the solution after a very long time. Actually run your program through to completion before posting.
#Tips
#
#There are an impossibly large number of different formulas for a given integer. You can't check them all. But you don't have to. You can always express the complexity of a number in terms of the complexity of two smaller numbers. The complexity of a number A > 1 is always equal to the minimum possible complexity of B plus the complexity of C, where either B*C = A or B+C = A. In mathematical terms:
#
#complexity(A) = min(P(A), S(A))
#P(A) = min(complexity(B) + complexity(C) | B*C = A)
#S(A) = min(complexity(B) + complexity(C) | B+C = A)
#
#If you have a minimal formula, you can tell which it is. For instance, the minimal formula for 5678 is:
#
#5678 = (1+4*4)*(1+3*3*(1+3*3*4))
#
#This is essentially saying 5678 = 17*334, where 17 = 1+4*4 (with a complexity of 9) and 334 = 1+3*3*(1+3*3*4) (with a complexity of 18), with a total complexity of 9+18 = 27. By checking every such pair, we would see that 27 is the minimum possible sum.
#
#The simplest thing to do is check every possible pair of numbers whose sum is 5678, and every possible pair of numbers whose product is 5678, and take the minimum sum of the complexity of the two numbers in the pair.
#Notes
#
#Integer complexity was featured in this subreddit 6 years ago in Challenge #31 [intermediate]. I tried to make it easier this time by giving some tips. Also, you don't need to find a formula, just get the value of the complexity.
#Optional bonus
#
#How fast can you get the sum of the integer complexities for all numbers from 1 to 1,000,000 inclusive? For this bonus, you may assume that the complexity of A is always equal to one of the following:
#
#    1 + the complexity of A-1
#    the sum of the complexity of two factors of A
#
#Using the notation above, this means:
#
#S(A) = 1 + complexity(A-1)
#
#In fact this is not true in general, but the smallest A for which it's false is 353,942,783.
