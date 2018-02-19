#!bin/python3

# Description
#
# You run a moving truck business, and you can pack the most in your truck when you have stacks of equal size - no slack space. So, you're an enterprising person, and you want to write some code to help you along.
# Input Description
#
# You'll be given two numbers per line. The first number is the number of stacks of boxes to yield. The second is a list of boxes, one integer per size, to pack.
#
# Example:
#
# 3 34312332
#
# That says "make three stacks of boxes with sizes 3, 4, 3, 1 etc".
# Output Description
#
# Your program should emit the stack of boxes as a series of integers, one stack per line. From the above example:
#
# 331
# 322
# 34
#
# If you can't make equal sized stacks, your program should emit nothing.
# Challenge Input
#
# 3 912743471352
# 3 42137586
# 9 2
# 4 064876318535318
#
# Challenge Output
#
# 9124
# 7342
# 7135
#
# 426
# 138
# 75
#
# (nothing)
#
# 0665
# 4733
# 8315
# 881

import sys

num_stacks = int(input("Enter number of stacks: "));
boxes = list(map(int, input("Enter boxes: ")));

if sum(boxes) % num_stacks == 0:
    sep_stacks = sum(boxes) / num_stacks;
else:
    print("fail");
    sys.exit();

boxes.sort(reverse=True);

temp = [];
for index, x in enumerate(boxes):
    temp.append(x);
    if sum(temp) == sep_stacks:
        print(temp);
        boxes.remove(x);
        break;
    else:
        for z in boxes[index + 1:]:
            if sum(temp) + z == sep_stacks:
                temp.append(z);
                print(temp);
                for n in temp:
                    boxes.remove(n);
                temp.clear();
                break;
            elif sum(temp) + z > sep_stacks:
                continue;
            elif sum(temp) + z < sep_stacks:
                temp.append(z);
print(boxes);
