#include <iostream>

int main()
{
    std::cout << "Type           sizeof\n";
    std::cout << "----           ------\n";

    std::cout << "char           " << sizeof(char) << '\n';
    std::cout << "short          " << sizeof(short) << '\n';
    std::cout << "int            " << sizeof(int) << '\n';
    std::cout << "long           " << sizeof(long) << '\n';
    std::cout << "long long      " << sizeof(long long) << '\n';
    std::cout << "float          " << sizeof(float) << '\n';
    std::cout << "double         " << sizeof(double) << '\n';
    std::cout << "long double    " << sizeof(long double) << '\n';
    std::cout << "bool           " << sizeof(bool) << '\n';
    std::cout << "int*           " << sizeof(int *) << '\n';

    // copy initialization
    int a = 17;

    // direct initialization
    int b(17);

    // brace (uniform) initialization
    int c{17};

    // int x = 3.14 truncates the decimal part because it expects an integer not a decimal which causes an implicit narrowing conversion.
    // int narrow{3.14};

    auto price = 15.99;
    auto age = 23;

    int *d = nullptr;
    std::cout << "int* = " << sizeof(d) << std::endl;

    return 0;
}