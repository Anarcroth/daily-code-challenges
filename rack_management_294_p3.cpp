// Description
// Today's challenge is loosely inspired by the board game Scrabble. You will need to download the enable1 English word list in order to check your solution. You will also need the point value of each letter tile. For instance, a is worth 1, b is worth 3, etc. Here's the point values of the letters a through z:
//
// [1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10]
// For this challenge, the score of a word is defined as 1x the first letter's point value, plus 2x the second letters, 3x the third letter's, and so on. For instance, the score of the word daily is 1x2 + 2x1 + 3x1 + 4x1 + 5x4 = 31.
//
// Given a set of 10 tiles, find the highest score possible for a single word from the word list that can be made using the tiles.
//
// Examples
// In all these examples, there is a single word in the word list that has the maximum score, but that won't always be the case.
//
// highest("iogsvooely") -> 44 ("oology")
// highest("seevurtfci") -> 52 ("service")
// highest("vepredequi") -> 78 ("reequip")
// highest("umnyeoumcp") -> ???
// highest("orhvtudmcz") -> ???
// highest("fyilnprtia") -> ???
// Optional bonus 1
// Make your solution more efficient than testing every single word in the word list to see whether it can be formed. For this you can spend time "pre-processing" the word list however you like, as long as you don't need to know the tile set to do your pre-processing. The goal is, once you're given the set of tiles, to return your answer as quickly as possible.
//
// How fast can get the maximum score for each of 100,000 sets of 10 tiles? Here's a shell command to generate 100,000 random sets, if you want to challenge yourself:
//
// cat /dev/urandom | tr A-Z eeeeeaaaaiiiooonnrrttlsudg | tr -dc a-z | fold -w 10 | head -n 100000
// Optional bonus 2
// Handle up to 20 tiles, as well as blank tiles (represented with ?). These are "wild card" tiles that may stand in for any letter, but are always worth 0 points. For instance, "?ai?y" is a valid play (beacuse of the word daily) worth 1x0 + 2x1 + 3x1 + 4x0 + 5x4 = 25 points.
//
// highest("yleualaaoitoai??????") -> 171 ("semiautomatically")
// highest("afaimznqxtiaar??????") -> 239 ("ventriloquize")
// highest("yrkavtargoenem??????") -> ???
// highest("gasfreubevuiex??????") -> ???
// Here's a shell command for 20-set tiles that also includes a few blanks:
//
// cat /dev/urandom | tr A-Z eeeeeaaaaiiiooonnrrttlsudg | tr 0-9 ? | tr -dc a-z? | fold -w 20 | head -n 100000

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

int calc_score(std::string word)
{
     int temp_score = 0, final_score = 0;
     for (size_t c = 0; c < word.size(); c++)
     {
          switch(word[c])
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
          final_score += temp_score * (c + 1);
          temp_score = 0;
     }
     return final_score;
}

void pick_tiles(std::string &line, std::string &board)
{
     while (board.size() < 11)
     {
          char c;

          (std::rand() % 2 != 0) ? c = *line.begin() : c = *line.end();

          board.append(1, c);
          line.erase(std::find(line.begin(), line.end(), c));
     }
}

void play_for_word(std::ifstream &file, std::string &board)
{
     std::string word, output, max_score_word;
     short int wildcards = 0, max_score = 0, score = 0;
     while (file >> word)
     {
          std::for_each(board.begin(), board.end(), [&](char &c){ (c == '?') ? wildcards += 1 : wildcards += 0; });
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
     //TODO for every  word in the max score word, remove it from the board plus the wildcards and return the score and plays
}

int main()
{
     std::string line = "sd?zeioao?mluvepesceinfxt?wyiru?ie?giator?t??nuefje?l?odndrotpewlgoobiinysagacaqski?aeh?rbhaervtnl?m";
     std::string board, output, word, max_score_word;
     int score = 0, plays = 0;
     std::ifstream file("words1.txt");

     while (line.size() > 0)
     {
          pick_tiles(line, board);
          play_for_word(file, board);

     }

     std::cout << score << " -- " << plays;

     return 0;
}
