#!bin/python

import re

wrong_date =  input("Enter date: ");
wrong_date = re.split("[\s/-]", wrong_date);
correct_date = "";
for date in  wrong_date:
    if len(date) == 4 and wrong_date.index(date) == 2:
        correct_date += date + "-";
        correct_date += wrong_date[0] + "-";
        correct_date += wrong_date[1];
    elif len(date) == 4 and wrong_date.index(date) == 0:
        correct_date += date + "-";
        correct_date += wrong_date[1] + "-";
        correct_date += wrong_date[0];

print(correct_date);
