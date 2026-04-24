#include <iostream>

int main()
{
    int x; // int x = 0; or int x{0}; → safe initialization. initializing variables helps prevent bugs
    std::cout << x;
    return 0;
}