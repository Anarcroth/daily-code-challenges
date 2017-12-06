#include <iostream>
#include <string>
#include <algorithm>

bool check_pal(std::string num);

int main()
{
  std::string pal_number = " ";
  std::cout << "Enter a number: ";
  std::cin >> pal_number;
  bool ch = false;
  while (!ch)
    {
      std::cout << pal_number;
      std::string temp = pal_number;
      std::reverse(pal_number.begin(), pal_number.end());
      std::string num = std::to_string(std::stoi(temp) + std::stoi(pal_number));
      std::cout << num;
      if (check_pal(num))
        {
          std::cout << num << std::endl;
          ch = true;
        }
    }
  return 0;
}

bool check_pal(std::string num)
{
  size_t n;
  for (size_t i = 0; i < num.size(); i++)
    {
      while (num[i] == num[num.size() - i])
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
