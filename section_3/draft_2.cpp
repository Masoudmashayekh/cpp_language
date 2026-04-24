#include <iostream>


int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{ };
    std::cin >> input;
    return input;
}


int main()
{
    int number{ getValueFromUser() };
    std::cout << number << " double is: " << number * 2 << "\n";
    return 0;
}