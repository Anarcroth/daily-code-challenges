#include <iostream>
#include <string>
#include <numeric>
#include <vector>
#include <algorithm>
#include <set>

std::vector<int> kmp_table(std::vector<int> T, std::string words_sought)
{
  int pos = 1, cnd = 0;

  T[0] = -1;

  while (pos < words_sought.length())
    {
      if (words_sought[pos] == words_sought[cnd])
        {
          T[pos] = T[cnd];
          pos += 1;
          cnd += 1;
        }
      else
        {
          T[pos] = cnd;
          cnd = T[cnd];
          while (cnd >= 0 && words_sought[pos] != words_sought[cnd])
            {
              cnd = T[cnd];
            }
          pos += 1;
          cnd += 1;
        }
    }

  T[pos] = cnd;

  return T;
}

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

  std::cout << "STL implementation" << std::endl;

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

  std::cout << "KMP algorithm implementation" << std::endl;

  // Doesn't work
  /*
  for (auto & s : words_sought)
    {
      int m = 0, i = 0, np = 0;
      std::vector<int> T;
      T = kmp_table(T, s);
      std::vector<int> P;
      while (m + i < input.length())
        {
          if (s[i] == input[m + i])
            {
              i += 1;
              if (i == s.length())
                {
                  P[np] = m ;
                  np += 1;
                  m += i - T[i];
                  i -= T[i];
                }
            }
          else
            {
              if (T[i] > 1)
                {
                  m += i - T[i];
                  i -= T[i];
                }
              else
                {
                  m += i + 1;
                  i = 0;
                }
            }
        }
        }*/
  
  return 0;
}
