#include <iostream>
#include <string>

int main()
{
    std::cout << "Tell me your age: ";
    std::string name {};
    int age {};
    
    std::cin >> name >> age;
    std::cout << "Hi " << name << ". Your age is "<< age << ".\n";
    return 0;
}