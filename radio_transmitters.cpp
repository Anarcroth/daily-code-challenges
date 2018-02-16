#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

int main()
{
    int num_houses, transmitter_reach;
    std::cin >> num_houses;
    std::cin >> transmitter_reach;

    std::vector<int> houses;
    for (int i = 0; i < num_houses; i++)
    {
        int x;
        std::cin >> x;
        houses.push_back(x);
    }

    std::sort(houses.begin(), houses.end());

    int num_transmitters = 0;

    for (size_t i = 0; i < houses.size(); ++i)
    {
        std::cout << "i: " << i << std::endl;
        if (i >= houses.size() - 1)
        {
            break;
        }
        else if (std::abs(houses[i] - houses[i + transmitter_reach - 1]) <= transmitter_reach)
        {
            std::cout << houses[i] << "  " << houses[i + transmitter_reach - 1] << "  " << std::endl;
            num_transmitters += 1;
            i = i + transmitter_reach ;
            std::cout << "i after incr: " << i << std::endl;
        }
        else if (std::abs(houses[i] - houses[i - transmitter_reach]) <= transmitter_reach)
        {
            std::cout << houses[i] << "  " << houses[i + transmitter_reach - 1] << "  " << std::endl;
            num_transmitters += 1;
        }
    }

    std::cout << num_transmitters;
}
