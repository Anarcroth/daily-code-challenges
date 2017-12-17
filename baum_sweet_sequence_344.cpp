// Description
// In mathematics, the Baum–Sweet sequence is an infinite automatic sequence of 0s and 1s defined by the rule:
//
//      b_n = 1 if the binary representation of n contains no block of consecutive 0s of odd length;
// b_n = 0 otherwise;
// for n >= 0.
//
//      For example, b_4 = 1 because the binary representation of 4 is 100, which only contains one block of consecutive 0s of length 2; whereas b_5 = 0 because the binary representation of 5 is 101, which contains a block of consecutive 0s of length 1. When n is 19611206, b_n is 0 because:
//
//                                                                                                                                            19611206 = 1001010110011111001000110 base 2
//                                                                                                                                                 00 0 0  00     00 000  0 runs of 0s
//                                                                                                                                                 ^ ^            ^^^    odd length sequences
//                                                                                                                                                 Because we find an odd length sequence of 0s, b_n is 0.
//
//                                                                                                                                                 Challenge Description
//                                                                                                                                                 Your challenge today is to write a program that generates the Baum-Sweet sequence from 0 to some number n. For example, given "20" your program would emit:
//
//                                                                                                                                            1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0

#include <iostream>
#include <string>
#include <algorithm>

std::string to_binary(int n)
{
     std::string r;
     while(n!=0)
     {
          r = (n % 2 == 0 ? "0" : "1") + r;
          n /= 2;
     }
     return r;
}

int main()
{
     int input;
     std::cin >> input;
     for (int i = 0; i < input; i++)
     {
          std::string b_num = to_binary(i);
          std::string tmp = "";
          // std::for_each(b_num.begin(), b_num.end(), [&](char &c) {
          //           (c == '0') ? tmp += c : tmp = "";n
          //           size_t next = tmp.find(c);
          //           //std::cout << next << " ";
          //           if (tmp[++next] != '0')
          //           {
          //                (tmp.size() % 2 == 0) ? std::cout << 1 << " " : std::cout << 0 << " ";
          //           }
          //      });

          for (int c = 0; c < b_num.length(); c++)
          {
               (c == '0') ? tmp += c : tmp = "";

          }
     }
     return 0;
}
