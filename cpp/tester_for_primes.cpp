#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

bool is_prime(int n);

bool is_emirp_prime(short int i);
bool is_additive_prime(int n);
bool is_mersenne_prime(int p);
bool is_twin_prime(short int n);

int main()
{
    short int i = 0;
    int n = 1;

    while (i < 100)
    {
        if (is_emirp_prime(n))
        {
            std::cout << n << " is an emirp!" << std::endl;
            i += 1;
        }
        n += 1;
    }

    i = 0;
    n = 1;
    while (i < 25)
    {
        if (is_additive_prime(n))
        {
            std::cout << n << " is an additive prime!" << std::endl;
            i += 1;
        }
        n += 1;
    }

    i = 0;
    n = 1;
    while (i < 31)
    {
        if (is_mersenne_prime(n))
        {
            std::cout << n << " and " << i << " are a mersenne prime!" << std::endl;
            i += 1;
        }
        n += 1;
    }

    n = 1;
    while (n < 1001)
    {
        if (is_twin_prime(n))
        {
            std::cout << "(" << n << ", " << n + 2 << ") are twin primes!" << std::endl;
        }
        n += 1;
    }
}

void aks_primality_test(int n)
{
    if (n > 2)
    {

    }
    else
    {
        return;
    }
}

bool is_prime(int n)
{
    switch(n)
    {
    case 2:
        return true;
    case 3:
        return true;
    }

    if (n % 2 == 0 || n % 3 == 0)
    {
        return false;
    }

    short int w = 2;
    short int i = 5;

    while (i * i <= n)
    {
        if (n % i == 0 )
        {
            return false;
        }
        i += w;
        w = 6 - w;
    }
    return true;
}

bool is_emirp_prime(short int i)
{
    std::string n = std::to_string(i);
    std::string rev_n(n);
    std::reverse(rev_n.begin(), rev_n.end());
    return (is_prime(std::stoi(n)) &&
            is_prime(std::stoi(rev_n)) &&
            rev_n != n) ? true : false;
}

bool is_additive_prime(int n)
{
    short int sum = 0;
    short int temp = n;
    while (temp > 0)
    {
        sum += temp % 10;
        temp /= 10;
    }

    return (is_prime(sum) && is_prime(n)) ? true : false;
}

bool is_mersenne_prime(int p)
{
    return (is_prime(std::pow(2, p) - 1)) ? true : false;
}

bool is_twin_prime(short int n)
{
    return (is_prime(n) && is_prime(n + 2)) ? true : false;
}
