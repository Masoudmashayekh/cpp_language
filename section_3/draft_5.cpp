#include <iostream>


int add(int x, int y)
{
    return x + y;
}


int main()
{
    std::cout << "Enter an integer: ";
    int x{};
    std::cin >> x;

    std::cout << "Enter an integer: ";
    int y{};
    std::cin >> y;
    
    std::cout << add(x, y);
}