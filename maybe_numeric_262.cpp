#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

std::string maybe_numeric(std::string& maybe)
{
     std::string nums = "1234567890 .eABCDEFx";
     std::string answr = "";

     for (char &c : maybe)
     {
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
                    answr = "Numeric";
               }
               else
               {
                    answr = "String";
                    break;
               }
     };

     return answr;
}

int main()
{
     std::string maybe;
     std::getline(std::cin, maybe);
     std::string delimiter = "`";
     std::vector<std::string> line;
     size_t start = 0;
     size_t end = 0;
     size_t len = 0;

     do
     {
          end = maybe.find(delimiter,start);
          len = end - start;
          line.emplace_back(maybe.substr(start, len));
          start += len + delimiter.length();

     } while (end != std::string::npos);

     for (std::string s : line)
     {
          std::cout << s << " ";
          std::cout << maybe_numeric(s) << std::endl;
     }

     return 0;
}
