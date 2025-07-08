#include "Fixed.hpp"

int main() {
    Fixed a;           // Default
    Fixed b(a);        // Copy constructor
    Fixed c;           // Default
    c = b;             // Copy assignment

	std::cout << "\n------------------------\n";

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;

    return 0;
}