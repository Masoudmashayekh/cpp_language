#include <iostream>


int main()
{
    int number{ };
    std::cout << "Please enter a number: ";
    std::cin >> number;
    std::cout << "Double that number is: " << number * 2 << "\n";
    return 0;
}