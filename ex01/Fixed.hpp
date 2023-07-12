#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	Fixed(int);
	Fixed(float);
	Fixed(const Fixed &other);
	Fixed &operator=(const Fixed &other);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;
};

std::ostream& operator<<(std::ostream& os, const Fixed &other);

#endif