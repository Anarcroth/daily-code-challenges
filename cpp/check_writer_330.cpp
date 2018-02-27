// Description:
// Given a dollar amount between 0.00 and 999,999.00, create a program that will provide a worded representation of a dollar amount on a check.
//
// Input:
// You will be given one line, the dollar amount as a float or integer. It can be as follows:
//
// 400120.0
// 400120.00
// 400120
// Output:
// This will be what you would write on a check for the dollar amount.
//
// Four hundred thousand, one hundred twenty dollars and zero cents.
// edit: There is no and between hundred and twenty, thank you /u/AllanBz
//
// Challenge Inputs:
// 333.88
// 742388.15
// 919616.12
// 12.11
// 2.0
// Challenge Outputs:
// Three hundred thirty three dollars and eighty eight cents.
// Seven hundred forty two thousand, three hundred eighty eight dollars and fifteen cents.
// Nine hundred nineteen thousand, six hundred sixteen dollars and twelve cents.
// Twelve dollars and eleven cents.
// Two dollars and zero cents.
// Bonus:
// While I had a difficult time finding an official listing of the world's total wealth, many sources estimate it to be in the trillions of dollars. Extend this program to handle sums up to 999,999,999,999,999.99

#include <iostream>
#include <string>
#include <vector>

// Optimization chance: just use 9 to 4 as standard numbers and append the suffix accordingly without doing useless and long switch cases

std::string get_singles(char &c)
{
     switch(c)
     {
     case '9':
          return "nine";
     case '8':
          return "eight";
     case '7':
          return "seven";
     case '6':
          return "six";
     case '5':
          return "five";
     case '4':
          return "four";
     case '3':
          return "three";
     case '2':
          return "two";
     case '1':
          return "one";
     case '0':
          return "zero";
     }
     return "";
}

std::string get_teens(char &c)
{
     switch(c)
     {
     case '9':
          return "nineteen";
     case '8':
          return "eighteen";
     case '7':
          return "seventeen";
     case '6':
          return "sixteen";
     case '5':
          return "fifteen";
     case '4':
          return "fourteen";
     case '3':
          return "thirteen";
     case '2':
          return "twelve";
     case '1':
          return "ALEVEN";
     }
     return "";
}

std::string get_tens(std::string &n)
{
     switch(n[0])
     {
     case '9':
          return "ninety";
     case '8':
          return "eighty";
     case '7':
          return "seventy";
     case '6':
          return "sixty";
     case '5':
          return "fifty";
     case '4':
          return "forty";
     case '3':
          return "thirty";
     case '2':
          return "twenty";
     case '1':
          return get_teens(n[1]);
     case '0':
          return get_singles(n[1]);
     }
     return "";
}

int main()
{
     std::string check;
     std::getline(std::cin, check);

     std::vector<std::string> nums = {"trillion", "billion", "million", "thousand", "hundred"};



     return 0;
}
