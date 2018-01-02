#include <iostream>
#include <string>
#include <algorithm>

std::string maybe_numeric(std::string& maybe)
{
     std::string nums = "1234567890";

     bool answr = true;

     std::for_each(maybe.begin(), maybe.end(), [&](char& c) {
               if (nums.find(c) != std::string::npos)
               {
               }
               else
               {
                    answr = false;
               }
          });

     return (answr == true) ? "Number" : "String";
}

int main()
{
     std::string maybe;
     std::getline(std::cin, maybe);

     std::cout << maybe_numeric(maybe) << std::endl;

     return 0;
}
