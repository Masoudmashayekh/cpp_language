#include <iostream>


int getValueFromUser()
{
    std::cout << "Enter an integer: ";
    int input{ };
    std::cin >> input;
    return input;
}


void printDouble(int number)
{
    std::cout << number << " double is: " << number * 2 << "\n";
}


int main()
{
    int number{ getValueFromUser() };
    printDouble(number);
    return 0;
}