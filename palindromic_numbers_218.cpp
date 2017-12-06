// Description
//
// To covert nearly any number into a palindromic number you operate by reversing the digits and adding and then repeating the steps until you get a palindromic number. Some require many steps.
// e.g. 24 gets palindromic after 1 steps: 66 -> 24 + 42 = 66
// while 28 gets palindromic after 2 steps: 121 -> 28 + 82 = 110, so 110 + 11 (110 reversed) = 121.
// Note that, as an example, 196 never gets palindromic (at least according to researchers, at least never in reasonable time). Several numbers never appear to approach being palindromic.
// Input Description
//
// You will be given a number, one per line. Example:
// 11
// 68
// Output Description
//
// You will describe how many steps it took to get it to be palindromic, and what the resulting palindrome is. Example:
// 11 gets palindromic after 0 steps: 11
// 68 gets palindromic after 3 steps: 1111
// Challenge Input
//
// 123
// 286
// 196196871
// Challenge Output
//
// 123 gets palindromic after 1 steps: 444
// 286 gets palindromic after 23 steps: 8813200023188
// 196196871 gets palindromic after 45 steps: 4478555400006996000045558744
// Note
//
// Bonus: see which input numbers, through 1000, yield identical palindromes.
// Bonus 2: See which numbers don't get palindromic in under 10000 steps. Numbers that never converge are called Lychrel numbers.

#include <iostream>
#include <string>
#include <algorithm>

bool check_pal(std::string num);

int main()
{
  std::string pal_number = " ";
  std::cout << "Enter a number: ";
  std::cin >> pal_number;
  for (int i = 0; i < 1000; i++)
  {
    std::string temp = pal_number;
    std::reverse(pal_number.begin(), pal_number.end());
    int num = std::stoi(temp) + std::stoi(pal_number);

    if (check_pal(std::to_string(num)))
      {
        std::cout << num << std::endl;
        std::abort();
      }
    }
  return 0;
}

bool check_pal(std::string num)
{
  size_t n;
  for (size_t i = 0; i < 1000; i++)
    {
      if (num[i] == num[1000 - i])
        {
          n += 1;
          if (n == num.size())
            {
              return true;
            }
        }
    }
  return false;
}
