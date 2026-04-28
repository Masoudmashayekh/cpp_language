#include <iostream>

#define PRINT_JOE
#define FOO 9

int main()
{
    #ifdef PRINT_JOE
    std::cout << "Joe" << "\n";
    #endif

    #ifndef PRINT_BOB
    std::cout << "Bob not define" << "\n";
    #endif

    #ifdef FOO
    std::cout << FOO << "\n";
    #endif

    return 0;
}