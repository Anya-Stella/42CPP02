#include "Fixed.hpp"
#include <cmath>

// Orthodox Canonical Form
Fixed::Fixed() : _rawBits(0)
{
	std::cout << "Default constructor called\n";
}

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

// ex constructor
Fixed::Fixed(const int	val) : _rawBits(val << _fractionalBits)
{
	std::cout << "Int constructor called\n";
}

// val * 256
Fixed::Fixed(const float	val) : _rawBits(static_cast<int>(roundf(val * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called\n";
}

// convert
float	Fixed::toFloat( void ) const
{
	return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int		Fixed::toInt( void ) const
{
	return (_rawBits >> _fractionalBits);
}

// getter & setter
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

// overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
