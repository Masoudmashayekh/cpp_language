#include <iostream>


int add(int x, int y);

int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
    return 0;
}

// g++ draft_7_main.cpp draft_7.cpp ==> ./a.out