#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
  int output = 0;
  int size, queries_num;

  std::cout << "Enter size of cannibal numbers: ";
  std::cin >> size;

  std::cout << "Enter number of queries: ";
  std::cin >> queries_num;

  std::vector<int> cannibal_nums;
  std::vector<int> cannibal_nums_copy;
  for (int x = 0; x < size; x++)
    {
      int n;
      std::cin >> n;
      cannibal_nums.push_back(n);
    }

  std::sort(cannibal_nums.rbegin(), cannibal_nums.rend());
  // Code to handle unique items or not.
  std::unique(cannibal_nums.begin(), cannibal_nums.end());

  for (int x = 1; x <= queries_num; x++)
    {
      int border_value;
      std::cout << "Enter a border value: ";
      std::cin >> border_value;

      cannibal_nums_copy = cannibal_nums;

      for (std::vector<int>::iterator it = cannibal_nums_copy.begin(); it != cannibal_nums_copy.end(); ++it)
        {
          if (*it >= border_value)
            {
              std::cout << "from first check " << *it << std::endl;
              output += 1;
              continue;
            }
          else if ((int)(*it + cannibal_nums_copy.size() - (it - cannibal_nums_copy.begin()) - 1) >= border_value)
            {
              cannibal_nums_copy.erase(std::remove(cannibal_nums_copy.begin(), cannibal_nums_copy.end(),
                                                   *std::min_element(cannibal_nums_copy.begin(), cannibal_nums_copy.end())),
                                       cannibal_nums_copy.end());
              output += 1;
              continue;
            }
        }
      std::cout << "Query " << x << " has a value of: " << output << std::endl;
      output = 0;
    }

  return 0;
}
