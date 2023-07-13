#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

class Fixed{
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(int);
	Fixed(float);
	Fixed(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed& operator=(const Fixed &other);

	bool operator>(const Fixed &other) const;
	bool operator<(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed operator+(const Fixed &other) const;
	Fixed operator-(const Fixed &other) const;
	Fixed operator*(const Fixed &other) const;
	Fixed operator/(const Fixed &other) const;

	Fixed &operator++(void);// pre
	Fixed operator++(int);// post

	Fixed &operator--(void);
	Fixed operator--(int);

	Fixed min(const Fixed &, const Fixed &);
	Fixed min(const int, const int);
	Fixed max(const Fixed &, const Fixed &);
	Fixed max(const int, const int);
};
/*
	1 000 0000
	음수 
*/

std::ostream& operator<<(std::ostream& os, const Fixed &other);

#endif