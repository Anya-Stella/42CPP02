#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int _rawBits;
	static const int _fractionalBits = 8;

public:
	// constructor
	Fixed();

	// copy constructorr
	Fixed(const Fixed &other);

	// copy asignment operator overload.
	Fixed &operator=(const Fixed &other);

	// destructor
	~Fixed();

	// getter
	int getRawBits() const;

	// setter
	void setRawBits(int const raw);
};
#endif