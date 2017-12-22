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
