#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	Fixed();
	Fixed(const int		val);
	Fixed(const float	val);
	Fixed(const Fixed	&other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	// compare
	bool	operator>(const Fixed	&other)	const;
	bool	operator<(const Fixed	&other)	const;
	bool	operator>=(const Fixed	&other)	const;
	bool	operator<=(const Fixed	&other)	const;
	bool	operator==(const Fixed	&other)	const;
	bool	operator!=(const Fixed	&other)	const;

	// math
	Fixed	operator+(const Fixed	&other)	const;
	Fixed	operator-(const Fixed	&other)	const;
	Fixed	operator*(const Fixed	&other)	const;
	Fixed	operator/(const Fixed	&other)	const;

	// increment & decrement
	Fixed	&operator++();
	Fixed	operator++(int);
	Fixed	&operator--();
	Fixed	operator--(int);

	// converter
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// getter & setter
	int getRawBits() const;
	void setRawBits(int const raw);

	// min / max
	static Fixed		&min(Fixed &a, Fixed &b);
	static const Fixed	&min(const Fixed& a, const Fixed& b);
	static Fixed		&max(Fixed &a, Fixed &b);
	static const Fixed	&max(const Fixed& a, const Fixed& b);
};

std::ostream &operator<<(std::ostream& os, const Fixed &fixed);
#endif