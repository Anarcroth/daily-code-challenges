// Description
//
// Help! My keyboard is broken, only a few keys work any more. If I tell you what keys work, can you tell me what words I can write?
//   (You should use the trusty enable1.txt file, or /usr/share/dict/words to chose your valid English words from.)
//   Input Description
//
//   You'll be given a line with a single integer on it, telling you how many lines to read. Then you'll be given that many lines, each line a list of letters representing the keys that work on my keyboard. Example:
//       3
//       abcd
//   qwer
//   hjklo
//   Output Description
//
//   Your program should emit the longest valid English language word you can make for each keyboard configuration.
//   abcd = bacaba
//   qwer = ewerer
//   hjklo = kolokolo
//   Challenge Input
//
//   4
//   edcf
//   bnik
//   poil
//   vybu
//   Challenge Output
//
//   edcf = deedeed
//   bnik = bikini
//   poil = pililloo
//   vybu = bubby

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <utility>

int main()
{
  std::ifstream in("words");

  std::vector<std::pair <std::string, std::string> > words;
  std::string s;
  std::getline(std::cin, s);
  words.emplace_back(std::make_pair(s, ""));

  std::string file_word = "";

  while (std::getline(in, file_word))
    {
      for (auto& p : words)
        {
          if (p.first.size() > file_word.size())
            {
              continue;
            }
          else
            {
              bool match = true;
              for (char a : file_word)
                {
                  if (p.first.find(a) == std::string::npos)
                    {
                      match = false;
                      break;
                    }
                }
              if (match && p.second.size() < file_word.size())
                {
                  p.second = file_word;
                }
            }
        }
    }

  in.close();

  for (const auto& p : words)
    {
      std::cout << p.first << " " << p.second << std::endl;
    }

  return 0;
}
