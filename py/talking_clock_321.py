#!/bin/python

# Description
# No more hiding from your alarm clock! You've decided you want your computer to keep you updated on the time so you're never late again. A talking clock takes a 24-hour time and translates it into words.
# Input Description
# An hour (0-23) followed by a colon followed by the minute (0-59).
#   Output Description
#   The time in words, using 12-hour format followed by am or pm.
#   Sample Input data
#   00:00
#      01:30
#      12:05
#      14:01
#      20:29
#      21:00
#      Sample Output data
#   It's twelve am
# It's one thirty am
#   It's twelve oh five pm
# It's two oh one pm
#   It's eight twenty nine pm
# It's nine pm

import string

time = raw_input("Enter a time: ");

hours = int(time[0:2]);
minutes = int(time[3:]);

one_to_twelve = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve"];
tens = ["ten", "twenty", "thirty", "forty", "fifty", "twelve"];

h = "";
m = "";

if hours == 0:
    h = one_to_twelve[11];
else:
    h = one_to_twelve[hours % 12 - 1] + " ";

a_or_p_m = "pm" if hours > 11 else "am";

if minutes == 0:
    m = " ";
elif minutes < 10:
    m = "oh " + one_to_twelve[minutes - 1] + " ";
else:
    m = tens[minutes / 10 - 1] + " " + one_to_twelve[minutes % 10 - 1] + " " if minutes % 10 == 0 else "";

print "It's " + h + m + a_or_p_m;
