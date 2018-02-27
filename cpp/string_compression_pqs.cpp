// 1.6 String Compression: Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become a2blc5a3. If the
//   "compressed" string would not become smaller than the original string, your method should return
//   the original string. You can assume the string has only uppercase and lowercase letters (a - z).

#include <iostream>
#include <string>
#include <vector>

int main()
{
  std::string input;
  std::getline(std::cin, input);

  std::vector<std::string> output;

  for (size_t s = 0; s < input.size(); s++)
    {
      int n = 0;
      char c;
      for (size_t z = s; z < input.size(); z++)
        {
          if (input[s] == input[z])
            {
              c = std::tolower(input[s]);
              n += 1;
            }
          else
            {
              break;
            }
        }
      s += n - 1;
      output.push_back(c + std::to_string(n));
    }

  for (auto it = output.begin(); it != output.end(); ++it)
    {
      std::cout << *it;
    }

  return 0;
}
