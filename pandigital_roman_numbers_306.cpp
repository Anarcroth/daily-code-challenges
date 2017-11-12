// Description
//
// 1474 is a pandigital in Roman numerals (MCDLXXIV). It uses each of the symbols I, V, X, L, C, and M at least once. Your challenge today is to find the small handful of pandigital Roman numbers up to 2000.
//   Output Description
//
//   A list of numbers. Example:
//   1 (I), 2 (II), 3 (III), 8 (VIII) (Examples only, these are not pandigital Roman numbers)
//   Challenge Input
//
//   Find all numbers that are pandigital in Roman numerals using each of the symbols I, V, X, L, C, D and M exactly once.
//   Challenge Input Solution
//
//   1444, 1446, 1464, 1466, 1644, 1646, 1664, 1666
//   See OEIS sequence A105416 for more information.

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

std::string to_roman(int value)
{
  struct romandata_t { int value; char const* numeral; };
  static romandata_t const romandata[] =
    { 1000, "M",
      900, "CM",
      500, "D",
      400, "CD",
      100, "C",
      90, "XC",
      50, "L",
      40, "XL",
      10, "X",
      9, "IX",
      5, "V",
      4, "IV",
      1, "I",
      0, NULL }; // end marker

  std::string result;
  for (romandata_t const* current = romandata; current->value > 0; ++current)
    {
      while (value >= current->value)
        {
          result += current->numeral;
          value  -= current->value;
        }
    }
  return result;
}

int main()
{
  std::string pandigitals = "IVXLCDM";

  for (int i = 1; i <= 2000; ++i)
    {
      do
        {
          if (to_roman(i) == pandigitals)
            {
              std::cout << i << std::endl;
            }
        } while (std::next_permutation(pandigitals.begin(), pandigitals.end()));
    }
}
