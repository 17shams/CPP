#include <iostream>
#include "converter.h"
#include "converter.h"

int main()
{

    double temperature{};
    char scale{};

    std::cout << "Enter a temperature: ";
    std::cin >> temperature;

    std::cout << "Enter the scale (C or F): ";
    std::cin >> scale;

    switch (scale)
    {

    case 'C':
    case 'c':
        std::cout << temperature << " C = " << celsiusToFahrenheit(temperature) << " F" << std::endl;
        break;

    case 'F':
    case 'f':
        std::cout << temperature << " F = " << fahrenheitToCelsius(temperature) << " C" << std::endl;
        break;
    default:
        std::cout << "Error. Please enter either 'C/c' or 'F/f'" << std::endl;
        break;
    }
    return 0;
}