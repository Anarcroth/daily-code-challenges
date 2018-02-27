// Description
//
// You were hired to create words for a new language. However, your boss wants these words to follow a strict pattern of consonants and vowels. You are bad at creating words by yourself, so you decide it would be best to randomly generate them.
//   Your task is to create a program that generates a random word given a pattern of consonants (c) and vowels (v).
//   Input Description
//
//   Any string of the letters c and v, uppercase or lowercase.
//   Output Description
//
//   A random lowercase string of letters in which consonants (bcdfghjklmnpqrstvwxyz) occupy the given 'c' indices and vowels (aeiou) occupy the given 'v' indices.
//   Sample Inputs
//
//   cvcvcc
//
//   CcvV
//
//   cvcvcvcvcvcvcvcvcvcv
//   Sample Outputs
//
//   litunn
//
//   ytie
//
//   poxuyusovevivikutire
//   Bonus
//
//   Error handling: make your program react when a user inputs a pattern that doesn't consist of only c's and v's.
// When the user inputs a capital C or V, capitalize the letter in that index of the output.

#include <iostream>
#include <string>
#include <algorithm>
#include <random>
#include <locale>

int main()
{
  std::string input;
  std::getline(std::cin, input);

  std::for_each(input.begin(), input.end(), [](char &c)
    {
      std::locale loc;
      std::mt19937 rng;
      rng.seed(std::random_device()());
      std::uniform_int_distribution<std::mt19937::result_type> dist5(1,5);
      std::uniform_int_distribution<std::mt19937::result_type> dist21(1,21);

      std::string consonants = "bcdfghjklmnpqrstvwxyz";
      std::string vowels = "aeiou";

      switch (c)
        {
        case 'c': std::cout << consonants[dist21(rng)]; break;
        case 'v': std::cout << vowels[dist5(rng)]; break;
        case 'C': std::cout << std::toupper(vowels[dist21(rng)], loc); break;
        case 'V': std::cout << std::toupper(vowels[dist5(rng)], loc); break;
        default:
          break;
        }
    });

  return 0;
}
