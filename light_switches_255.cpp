#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <utility>
#include <sstream>
#include <iterator>
#include <cstdlib>
#include <unistd.h>

void display_bulbs(std::vector<bool>& bulbs)
{
     std::for_each(bulbs.begin(), bulbs.end(), [](bool x) { std::cout << x << " ";});
}

int main()
{
     long int n_bulbs;
     std::cout << "Enter number of bulbs: ";
     std::cin >> n_bulbs;

     std::vector<bool> bulbs(n_bulbs);

     int playtime;
     std::cout << "Enter playtime: ";
     std::cin >> playtime;

     for(int i = 0; i < playtime; i++)
     {
          // clear screen
          printf("\033c");

          display_bulbs(bulbs);

          std::cout << "\n\nEnter lower bound: ";
          int n1 = 0, n2 = 0;
          std::cin >> n1;
          std::cout << "Enter upper bound: ";
          std::cin >> n2;

          if (n1 <= n2)
          {
               while (n1 <= n2)
               {
                    bulbs[n1] = !bulbs[n1];
                    n1 += 1;
               }
          }
          else
          {
               while (n2 <= n1)
               {
                    bulbs[n2] = !bulbs[n2];
                    n2 += 1;
               }
          }
     }

     // clear screen
     printf("\033c");

     display_bulbs(bulbs);

     static int final_score = 0;

     std::for_each(bulbs.begin(), bulbs.end(), [](bool x) {if (x) { final_score += 1;}});

     std::cout << "\n\nThere are  " << final_score << " bulbs left on!" << std::endl;

     return 0;
}
