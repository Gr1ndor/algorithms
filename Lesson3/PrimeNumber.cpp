#include <iostream>

int main()
{
    int x = 0, i = 3;
    std::cout << "Enter x\n";
    std::cin >> x;
    if (x%2 > 0 || x == 2)
    {
        while (i*i <= x)
        {
            if (x % i == 0)
            {
                std::cout << "No prime\n";
                return 0;
            }
            i += 2;
        }
        std::cout << "Prime\n";
        return 0;
    }
    else
    {
        std::cout << "No prime\n";
    }
    return 0;
}