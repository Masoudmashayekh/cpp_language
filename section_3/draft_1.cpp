#include <iostream>

// Function
void doPrint()
{
    std::cout << "In doPrint()\n";
}

int main()
{
    std::cout << "starting main()\n";
    doPrint();
    std::cout << "Ending main()\n";
    return 0;
}