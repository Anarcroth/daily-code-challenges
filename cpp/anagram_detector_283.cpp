// Description
//
// An anagram is a form of word play, where you take a word (or set of words) and form a different word (or different set of words) that use the same letters, just rearranged. All words must be valid spelling, and shuffling words around doesn't count.
// Some serious word play aficionados find that some anagrams can contain meaning, like "Clint Eastwood" and "Old West Action", or "silent" and "listen".
// Someone once said, "All the life's wisdom can be found in anagrams. Anagrams never lie." How they don't lie is beyond me, but there you go.
// Punctuation, spaces, and capitalization don't matter, just treat the letters as you would scrabble tiles.
// Input Description
//
// You'll be given two words or sets of words separated by a question mark. Your task is to replace the question mark with information about the validity of the anagram. Example:
// "Clint Eastwood" ? "Old West Action"
// "parliament" ? "partial man"
// Output Description
//
// You should replace the question mark with some marker about the validity of the anagram proposed. Example:
// "Clint Eastwood" is an anagram of "Old West Action"
// "parliament" is NOT an anagram of "partial man"
// Challenge Input
//
// "wisdom" ? "mid sow"
// "Seth Rogan" ? "Gathers No"
// "Reddit" ? "Eat Dirt"
// "Schoolmaster" ? "The classroom"
// "Astronomers" ? "Moon starer"
// "Vacation Times" ? "I'm Not as Active"
// "Dormitory" ? "Dirty Rooms"
// Challenge Output
//
// "wisdom" is an anagram of "mid sow"
// "Seth Rogan" is an anagram of "Gathers No"
// "Reddit" is NOT an anagram of "Eat Dirt"
// "Schoolmaster" is an anagram of "The classroom"
// "Astronomers" is NOT an anagram of "Moon starer"
// "Vacation Times" is an anagram of "I'm Not as Active"
// "Dormitory" is NOT an anagram of "Dirty Rooms"


#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>

int main()
{
  std::vector<char> al1, al2;
  std::string alliteration;
  std::getline(std::cin, alliteration);
  for (std::string::iterator s = alliteration.begin(); s != alliteration.end(); ++s)
    {
      if (*s != ' ' && *s != '\'' &&
          s - alliteration.begin() < std::find(alliteration.begin(), alliteration.end(), '?') - alliteration.begin())
        {
          al1.push_back(std::tolower(*s));
        }
      else if (*s != ' ' && *s != '\'' &&
               s - alliteration.begin() > std::find(alliteration.begin(), alliteration.end(), '?') - alliteration.begin())
        {
          al2.push_back(std::tolower(*s));
        }
    }
  std::sort(al1.begin(), al1.end());
  std::sort(al2.begin(), al2.end());

  if (al1 == al2)
    {
      std::cout << "is an anagram" << std::endl;
    }
  else
    {
      std::cout << "is NOT an anagram" << std::endl;
    }
}
