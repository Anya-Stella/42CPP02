#include "Fixed.hpp"

Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

// we can use "_rawBits" without the use of getter.
Fixed::Fixed(const Fixed &other) : _rawBits(other._rawBits)
{
	std::cout << "Copy constructor called\n";
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy asignment operator called\n";
	if (this != &other)
		_rawBits = other._rawBits;
	return (*this);
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int	Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called\n";
	return (_rawBits);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called\n";
	_rawBits = raw;
}
