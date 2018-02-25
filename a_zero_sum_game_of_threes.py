#!bin/python3

# Description
#
# Let's pursue Monday's Game of Threes further!
#
# To make it more fun (and make it a 1-player instead of a 0-player game), let's change the rules a bit: You can now add any of [-2, -1, 1, 2] to reach a multiple of 3. This gives you two options at each step, instead of the original single option.
#
# With this modified rule, find a Threes sequence to get to 1, with this extra condition: The sum of all the numbers that were added must equal 0. If there is no possible correct solution, print Impossible.
# Sample Input:
#
# 929
#
# Sample Output:
#
# 929 1
# 310 -1
# 103 -1
# 34 2
# 12 0
# 4 -1
# 1
#
# Since 1 - 1 - 1 + 2 - 1 == 0, this is a correct solution.
# Bonus points
#
# Make your solution work (and run reasonably fast) for numbers up to your operating system's maximum long int value, or its equivalent. For some concrete test cases, try:
#
#     18446744073709551615
#     18446744073709551614

n = int(input("Enter a number: "));

sum_of_all_adds = 0;
while n > 1:
    if n % 3 == 0:
        print(int(n), "0");
        n /= 3;
    elif (n - 2) % 3 == 0:
        print (int(n), " -2");
        n = (n - 2) / 3;
        sum_of_all_adds -= 2;
    elif (n + 2) % 3 == 0:
        print (int(n), " +2");
        n = (n + 2) / 3;
        sum_of_all_adds += 2;
    elif (n - 1) % 3 == 0:
        print (int(n), " -1");
        n = (n - 1) / 3;
        sum_of_all_adds -= 1;
    elif (n + 1) % 3 == 0:
        print(int(n), " +1");
        n = (n + 1) / 3;
        sum_of_all_adds += 1;

print(int(n));
print(sum_of_all_adds);
