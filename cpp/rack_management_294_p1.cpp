// Description
// Today's challenge is inspired by the board game Scrabble. Given a set of 7 letter tiles and a word, determine whether you can make the given word using the given tiles.
//
// Feel free to format your input and output however you like. You don't need to read from your program's input if you don't want to - you can just write a function that does the logic. I'm representing a set of tiles as a single string, but you can represent it using whatever data structure you want.
//
// Examples
// scrabble("ladilmy", "daily") -> true
// scrabble("eerriin", "eerie") -> false
// scrabble("orrpgma", "program") -> true
// scrabble("orppgma", "program") -> false
// Optional Bonus 1
// Handle blank tiles (represented by "?"). These are "wild card" tiles that can stand in for any single letter.
//
// scrabble("pizza??", "pizzazz") -> true
// scrabble("piizza?", "pizzazz") -> false
// scrabble("a??????", "program") -> true
// scrabble("b??????", "program") -> false
// Optional Bonus 2
// Given a set of up to 20 letter tiles, determine the longest word from the enable1 English word list that can be formed using the tiles.
//
// longest("dcthoyueorza") ->  "coauthored"
// longest("uruqrnytrois") -> "turquois"
// longest("rryqeiaegicgeo??") -> "greengrocery"
// longest("udosjanyuiuebr??") -> "subordinately"
// longest("vaakojeaietg????????") -> "ovolactovegetarian"
// (For all of these examples, there is a unique longest word from the list. In the case of a tie, any word that's tied for the longest is a valid output.)
//
// Optional Bonus 3
// Consider the case where every tile you use is worth a certain number of points, given on the Wikpedia page for Scrabble. E.g. a is worth 1 point, b is worth 3 points, etc.
//
// For the purpose of this problem, if you use a blank tile to form a word, it counts as 0 points. For instance, spelling "program" from "progaaf????" gets you 8 points, because you have to use blanks for the m and one of the rs, spelling prog?a?. This scores 3 + 1 + 1 + 2 + 1 = 8 points, for the p, r, o, g, and a, respectively.
//
// Given a set of up to 20 tiles, determine the highest-scoring word from the word list that can be formed using the tiles.
//
// highest("dcthoyueorza") ->  "zydeco"
// highest("uruqrnytrois") -> "squinty"
// highest("rryqeiaegicgeo??") -> "reacquiring"
// highest("udosjanyuiuebr??") -> "jaybirds"
// highest("vaakojeaietg????????") -> "straightjacketed"

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

int calc_score(std::string word)
{
     int temp_score = 0;
     for (auto &c : word)
     {
          switch(c)
          {
          case 'a':
          case 'e':
          case 'i':
          case 'o':
          case 'n':
          case 'r':
          case 't':
          case 'l':
          case 's':
          case 'u':
               temp_score += 1; break;
          case 'd':
          case 'g':
               temp_score += 2; break;
          case 'b':
          case 'c':
          case 'm':
          case 'p':
               temp_score += 3; break;
          case 'f':
          case 'h':
          case 'v':
          case 'w':
          case 'y':
               temp_score += 4; break;
          case 'k':
               temp_score += 5; break;
          case 'j':
          case 'x':
               temp_score += 8; break;
          case 'q':
          case 'z':
               temp_score += 10; break;
          }
     }
     return temp_score;
}

int main()
{
     std::string board;
     std::getline(std::cin, board);
     std::string output;
     short int wildcards = 0;
     int score = 0, max_score = 0;

     std::for_each(board.begin(), board.end(), [&](char&c){ (c == '?') ? wildcards += 1 : wildcards += 0; });

     std::ifstream file("words1.txt");
     std::string word, max_score_word;
     while (file >> word)
     {
          std::string temp_board = board;
          for (auto &c : word)
          {
               try
               {
                    output.append(1, temp_board.at(temp_board.find(c)));
                    temp_board.erase(std::find(temp_board.begin(), temp_board.end(), c));
               }
               catch (std::exception e)
               {
               }
          }
          if ((wildcards == word.length() - output.length()) || (output == word))
          {
               score = calc_score(word);
               if (score > max_score)
               {
                    max_score_word = word;
                    max_score = score;
               }
          }
          else
          {
               output = "";
          }
     }

     std::cout << max_score_word << " -- " << max_score << std::endl;

     return 0;
}
