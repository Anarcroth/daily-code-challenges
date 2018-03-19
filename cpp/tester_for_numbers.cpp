#include <iostream>
#include <cstdint>

bool is_perfect(uint64_t n);
bool is_deficient(uint64_t n);
bool is_abundant(uint64_t n);
bool is_prime(uint64_t n);

uint64_t sum_of_divisors(uint64_t n);

int main()
{
    uint64_t n = 1;
    while (n < 251)
    {
        if (is_prime(n))
        {
            std::cout << n << " is prime!" << std::endl;
        }
        else if (is_perfect(n))
        {
            std::cout << n << " is perfect!" << std::endl;
        }
        else if(is_deficient(n))
        {
            std::cout << n << " is deficient!" << std::endl;
        }
        else if(is_abundant(n))
        {
            std::cout << n << " is abundant!" << std::endl;
        }

        n += 1;
    }
}

uint64_t sum_of_divisors(uint64_t n)
{
    uint64_t sum = 0;
    for (uint64_t i = 1; i < n; i++)
    {
        if (n % i == 0)
        {
            sum += i;
        }
    }
    return sum;
}

bool is_perfect(uint64_t n)
{
    return (sum_of_divisors(n) == n) ? true : false;
}

bool is_deficient(uint64_t n)
{
    return (sum_of_divisors(n) > n) ? true : false;
}

bool is_abundant(uint64_t n)
{
    return (sum_of_divisors(n) < n) ? true : false;
}

bool is_prime(uint64_t n)
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

    uint64_t i = 5;
    uint64_t w = 2;

    while (i * i <= n)
    {
        if (n % i == 0)
        {
            return false;
        }
        i += w;
        w = 6 - w;
    }
    return true;
}
