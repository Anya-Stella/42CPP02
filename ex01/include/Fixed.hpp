#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	// Orthodox Canonical Form
	Fixed();
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();

	// ex constructor
	Fixed(const int	val);
	Fixed(const float	val);

	// convert
	float	toFloat( void ) const;
	int		toInt( void ) const;

	// getter
	int getRawBits() const;

	// setter
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream& os, const Fixed &fixed);
#endif