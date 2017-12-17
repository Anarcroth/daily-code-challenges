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
