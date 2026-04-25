#include <iostream>


int add(int x, int y);   // Forward Declaration


int main()
{
    std::cout << "The sum of 3 and 4 is: " << add(3, 4) << "\n";
    return 0;
}


int add(int x, int y)
{
    return x + y;
}