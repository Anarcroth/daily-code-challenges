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
