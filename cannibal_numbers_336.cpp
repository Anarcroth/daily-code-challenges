// Description
//
// Imagine a given set of numbers wherein some are cannibals. We define a cannibal as a larger number can eat a smaller number and increase its value by 1. There are no restrictions on how many numbers any given number can consume. A number which has been consumed is no longer available.
//
// Your task is to determine the number of numbers which can have a value equal to or greater than a specified value.
// Input Description
//
// You'll be given two integers, i and j, on the first line. i indicates how many values you'll be given, and j indicates the number of queries.
//
// Example:
//
//  7 2
//  21 9 5 8 10 1 3
//  10 15
//
// Based on the above description, 7 is number of values that you will be given. 2 is the number of queries.
//
// That means -
// * Query 1 - How many numbers can have the value of at least 10
// * Query 2 - How many numbers can have the value of at least 15
// Output Description
//
// Your program should calculate and show the number of numbers which are equal to or greater than the desired number. For the sample input given, this will be -
//
//  4 2
//
// Explanation
//
// For Query 1 -
//
// The number 9 can consume the numbers 5 to raise its value to 10
//
// The number 8 can consume the numbers 1 and 3 to raise its value to 10.
//
// So including 21 and 10, we can get four numbers which have a value of at least 10.
//
// For Query 2 -
//
// The number 10 can consume the numbers 9,8,5,3, and 1 to raise its value to 15.
//
// So including 21, we can get two numbers which have a value of at least 15. 

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
