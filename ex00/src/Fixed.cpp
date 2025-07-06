#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called.\n";
}

Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called.\n";
}

Fixed& Fixed::operator=(const Fixed &other)
{
	std::cout << "\n";
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called.\n";
}

