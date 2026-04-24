#include <iostream>

int main()
{
    std::cout << "Tell me your age: ";
    int age {};
    std::cin >> age;
    std::cout << "Your age is "<< age << ".\n";
    return 0;
}