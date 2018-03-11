// Hackerland is a one-dimensional city with houses, where each house i is located at some xi on the x-axis. The Mayor wants to install radio transmitters on the roofs of the city's houses. Each transmitter has a range, k, meaning it can transmit a signal to all houses <= k units of distance away.
//
// Given a map of Hackerland and the value of , can you find and print the minimum number of transmitters needed to cover every house in the city? (Every house must be covered by at least one transmitter) Each transmitter must be installed on top of an existing house.
//
// Input Format
//
// The first line contains two space-separated integers describing the respective values of n(the number of houses in Hackerland) and k(the range of each transmitter).
// The second line contains n space-separated integers describing the respective locations of each house (i.e., x1, x2,...,xn).
//
// Constraints
//     1 <= n, k <= 10^5
//     1 <= xi <= 10^5
//     There may be more than one house at the same location.
//
// Output Format
//
// Print a single integer denoting the minimum number of transmitters needed to cover all the houses.
//
// Sample Input 0
//
// 5 1
// 1 2 3 4 5
//
// Sample Output 0
//
// 2
//
// Explanation 0
//
// The diagram below depicts our map of Hackerland:
//
// We can cover the entire city by installing transmitters on houses at locations 2 and 4. Thus, we print 2 on a new line.
//
// Sample Input 1
//
// 8 2
// 7 2 4 6 5 9 12 11
//
// Sample Output 1
//
// 3
//
// Explanation 1
//
// We can cover the entire city by installing transmitters on houses at locations 4, 9, and 12. Thus, we print 3 on a new line.

#include <iostream>
#include <vector>
#include <algorithm>

size_t shift_index(size_t i, const std::vector<int>& h, int hwt)
{
    while (i < h.size() && h[i] <= hwt)
    {
        i += 1;
    }
    return i;
}

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
    for (size_t i = 0; i < houses.size();)
    {
        int house_with_transmitter = houses[i] + transmitter_reach;
        i = shift_index(i, houses, house_with_transmitter);

        num_transmitters += 1;

        house_with_transmitter = houses[i - 1] + transmitter_reach;
        i = shift_index(i, houses, house_with_transmitter);
    }

    std::cout << num_transmitters;
    return 0;
}
