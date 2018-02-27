// Description
//
// Locate all repeating numbers in a given number of digits. The size of the number that gets repeated should be more than 1. You may either accept it as a series of digits or as a complete number. I shall explain this with examples:
//
// 11325992321982432123259
//
// We see that:
//
//     321 gets repeated 2 times
//     32 gets repeated 4 times
//     21 gets repeated 2 times
//     3259 gets repeated 2 times
//     25 gets repeated 2 times
//     59 gets repeated 2 times
//
// Or maybe you could have no repeating numbers:
//
// 1234565943210
//
// You must consider such a case:
//
// 9870209870409898
//
// Notice that 987 repeated itself twice (987, 987) and 98 repeated itself four times (98, 98, 987 and 987).
//
// Take a chunk "9999". Note that there are three 99s and two 999s.
//
// 9999 9999 9999
//
// 9999 9999
// Input Description
//
// Let the user enter 'n' number of digits or accept a whole number.
// Output Description
//
//     RepeatingNumber1:x RepeatingNumber2:y
//
// If no repeating digits exist, then display 0.
//
// Where x and y are the number of times it gets repeated.
// Challenge Input/Output
// Input 	Output
// 82156821568221 	8215682:2 821568:2 215682:2 82156:2 21568:2 15682:2 8215:2 2156:2 1568:2 5682:2 821:2 215:2 156:2 568:2 682:2 82:3 21:3 15:2 56:2 68:2
// 11111011110111011 	11110111:2 1111011:2 1110111:2 111101:2 111011:3 110111:2 11110:2 11101:3 11011:3 10111:2 1111:3 1110:3 1101:3 1011:3 0111:2 111:6 110:3 101:3 011:3 11:10 10:3 01:3
// 98778912332145 	0
// 124489903108444899 	44899:2 4489:2 4899:2 448:2 489:2 899:2 44:3 48:2 89:2 99:2
// Note
//
// Feel free to consider '0x' as a two digit number, or '0xy' as a three digit number. If you don't want to consider it like that, it's fine.

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
