#include <iostream>
#include <string>
#include <algorithm>

std::string maybe_numeric(std::string& maybe)
{
     std::string nums = "1234567890 .eABCDEFx";

     std::string answr = "";

     std::for_each(maybe.begin(), maybe.end(), [&](char& c) {
               if (nums.find(c) != std::string::npos)
               {
                    if (c == ' ')
                    {
                         answr = "Array";
                    }
                    else if (c == 'e')
                    {
                         answr = "Exponent";
                    }
                    else if (c == '.')
                    {
                         answr = "Decimal";
                    }
                    else if (c == 'x')
                    {
                         answr = "Hexadecimal";
                    }
               }
               else
               {
                    answr = "String";
               }
          });

     return answr;
}

int main()
{
     std::string maybe;
     std::getline(std::cin, maybe);

     std::cout << maybe_numeric(maybe) << std::endl;

     return 0;
}
