#!/bin/python3

import sys

# No calculations, just brute-force solution to given domain
# O(1)
def solve(year):
    # Year 1918: Feb 14 is 32nd day of year
    # Thus, 45 - 32 = 13 days remain
    # 13.09.1918 + 13 days = 26.09.1918
    if (year == 1918):
        return "26.09."+str(year)
    
    if (year <= 1917):
        if (year % 4 == 0):
            return "12.09."+str(year)
        else:
            return "13.09."+str(year)
    
    if year % 4 == 0 and year % 100 != 0:
        return "12.09."+str(year)
    elif year % 400 == 0:
        return "12.09."+str(year)
    else:
        return "13.09."+str(year)

year = int(input().strip())
result = solve(year)
print(result)
