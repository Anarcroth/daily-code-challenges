#include <iostream>
#include <string>
#include <algorithm>

int main()
{
    std::string input;
    std::getline(std::cin, input);
    std::string board;
    std::getline(std::cin, board);
    std::string word;
    for (auto &c : input)
    {
         word.append(1, board.at(board.find(c)));
         board.erase(std::find(board.begin(), board.end(), c));
    }

    (word == input) ? std::cout << "true" : std::cout << "false";

    return 0;
}
