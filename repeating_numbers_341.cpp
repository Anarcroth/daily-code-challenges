#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <set>

int main()
{
  std::string input;
  std::getline(std::cin, input);

  int counter = 0;
  std::vector<int> str_size(input.size() / 2);
  std::iota(str_size.begin(), str_size.end(), 2);
  std::set<std::string> words_sought;
  for (int i = 0; i < input.length() - 1; i++)
    {
      std::for_each(str_size.begin(), str_size.end(), [&](int& x) { words_sought.insert(input.substr(i, x)); });
    }

  std::for_each(words_sought.begin(), words_sought.end(), [&](std::string s) {
      size_t pos = input.find(s);
      while (pos != std::string::npos)
        {
          counter += 1;
          pos = input.find(s, pos + s.size());
        }
      if (counter > 1)
        {
          std::cout << s << " " << counter << std::endl;
        }
      counter = 0;
    });

  //TODO implement KMP algorithm to solve the task
//
//   for (auto & s : words_sought)
//     {
//       int m = 0, i = 0;
//       std::vector<int> T;
//
//       while (m + i < input.length())
//         {
//           if (s[i] == input[m + i])
//             {
//               i += 1;
//               if (i == s.length())
//                 {
//
//                 }
//             }
//         }
//     }


  return 0;
}
