#include <iostream>

int main()
{
    int x = 10;

    int* p = &x;

    std::cout << "Value of x: " << x << "\n";
    std::cout << "Address of x: " << &x << "\n";
    std::cout << "Pointer p stores: " << p << "\n";
    std::cout << "Value pointed to by p: " << *p << "\n";

    return 0;
}