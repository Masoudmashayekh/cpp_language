#include <iostream>
#include <string>
using namespace std; // It allows you to avoid writing std:: every time.

int main()
{
    cout << "Tell me your age: ";
    string name {};
    int age {};
    
    cin >> name >> age;
    cout << "Hi " << name << ". Your age is "<< age << ".\n";
    return 0;
}