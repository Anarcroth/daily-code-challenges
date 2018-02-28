// A vampire number has an even number of digits and is formed by multiplying a pair of numbers containing half the number of digits of the result.
// The digits are taken from the original number in any order. Pairs of trailing zeroes are not allowed. Examples include:
//
// 1260  =  21  *  60		1827  =  21  *  87		2187  =  27  *  81

#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <stdexcept>

int main()
{
    std::string input;
    std::cin >> input;

    if (input.size() % 2 != 0)
    {
        throw std::length_error("Input is not an even number!");
    }

    std::string vampire_num(input);
    std::set<int> separated_nums;
    do
    {
        std::string temp = vampire_num.substr(0, 2);
        separated_nums.insert(std::stoi(temp));
    } while (std::next_permutation(vampire_num.begin(), vampire_num.end()));

    for (auto i = separated_nums.begin(); i != separated_nums.end(); ++i)
    {
        int del = std::stoi(input)  / *i;
        if (separated_nums.find(del) != separated_nums.end() && del * *i == std::stoi(input))
        {
            std::cout << "The vampire pair is " << *i << ", " << del << std::endl;
            break;
        }
    }

    return 0;
}
