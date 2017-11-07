#include <iostream>
#include <vector>

int main()
{
  std::cout << "Enter a number: ";
  int n;
  std::cin >> n;

  std::vector<int> numbers;

  for (int i = 1; i <= n; i++)
    {
      numbers.push_back(i);
    }

  int step = 1;

  for (size_t i = 1; i < numbers.size(); i++)
    {
      numbers.erase(numbers.begin() + i);
    }

  while (step < (int)numbers.size())
    {
      for (int i = numbers[step] - 1; i < (int)numbers.size(); i += numbers[step] - 1)
        {
          numbers.erase(numbers.begin() + step);
        }
      step += 1;
    }

  for (auto it = numbers.begin(); it != numbers.end(); ++it)
    {
      if (*it == n)
        {
          std::cout << "The Lucky number is: " << *it << std::endl;
        }
      else
        {
          std::cout << *--it << " " << n << " " << *++it << std::endl;
        }
    }

  return  0;
}
