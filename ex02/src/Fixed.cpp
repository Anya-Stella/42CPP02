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

Fixed::Fixed(const int	val) : _rawBits(val << _fractionalBits)
{
	std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float	val) : _rawBits(static_cast<int>(roundf(val * (1 << _fractionalBits))))
{
	std::cout << "Float constructor called\n";
}






// compare
bool	Fixed::operator>(const Fixed	&other)	const
{
	return (_rawBits > other._rawBits);
}

bool	Fixed::operator<(const Fixed	&other)	const
{
	return (_rawBits < other._rawBits);
}

bool	Fixed::operator>=(const Fixed	&other)	const
{
	return (_rawBits >= other._rawBits);
}

bool	Fixed::operator<=(const Fixed	&other)	const
{
	return (_rawBits <= other._rawBits);
}

bool	Fixed::operator==(const Fixed	&other)	const
{
	return (_rawBits == other._rawBits);
}

bool	Fixed::operator!=(const Fixed	&other)	const
{
	return (_rawBits != other._rawBits);
}






// math
Fixed	Fixed::operator+(const Fixed	&other)	const
{
	Fixed	res;
	res._rawBits = _rawBits + other._rawBits;
	return (res);
}

Fixed	Fixed::operator-(const Fixed	&other)	const
{
	Fixed	res;
	res._rawBits = _rawBits - other._rawBits;
	return (res);
}

// 256 * 256 -> *256
Fixed	Fixed::operator*(const Fixed	&other)	const
{
	Fixed	res;
	long	temp = static_cast<long>(_rawBits) * other._rawBits;
	res._rawBits = static_cast<int>(temp >> _fractionalBits);
	return (res);
}

// to acuracy
Fixed	Fixed::operator/(const Fixed	&other)	const
{
	Fixed	res;
	long	temp = (static_cast<long>(_rawBits) << _fractionalBits) / other._rawBits;
	res._rawBits = static_cast<int>(temp);
	return (res);
}






// increments & decrement
Fixed	&Fixed::operator++()
{
	++_rawBits;
	return (*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed	temp(*this);
	++(*this);
	return (temp);
}

Fixed	&Fixed::operator--()
{
	--_rawBits;
	return (*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed	temp(*this);
	--(*this);
	return (temp);
}






// converter
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




// min / max
Fixed		&Fixed::min(Fixed &a, Fixed &b)
{
	return ((a < b) ? a : b);
}

const Fixed	&Fixed::min(const Fixed& a, const Fixed& b)
{
	return ((a < b) ? a : b);
}

Fixed		&Fixed::max(Fixed &a, Fixed &b)
{
	return ((a > b) ? a : b);
}

const Fixed	&Fixed::max(const Fixed& a, const Fixed& b)
{
	return ((a > b) ? a : b);
}




// overload
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return (os);
}
