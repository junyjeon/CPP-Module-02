#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
private:
	int value;
	static const int bits = 8;
public:
	Fixed();
	~Fixed();
	Fixed(int);
	Fixed(float);
	Fixed(const Fixed &);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;


	bool operator>(const Fixed &) const;
	bool operator<(const Fixed &) const;
	bool operator>=(const Fixed &) const;
	bool operator<=(const Fixed &) const;
	bool operator==(const Fixed &) const;
	bool operator!=(const Fixed &) const;

	Fixed &operator=(const Fixed &);
	Fixed operator+(const Fixed &) const;
	Fixed operator-(const Fixed &) const;
	Fixed operator*(const Fixed &) const;
	Fixed operator/(const Fixed &) const;

	Fixed &operator++(void);// pre
	Fixed &operator--(void);

	const Fixed operator++(int);// post
	const Fixed operator--(int);

	static const Fixed &min(const Fixed &, const Fixed &);
	static Fixed &min(Fixed &, Fixed &);
	static const Fixed &max(const Fixed &, const Fixed &);
	static Fixed &max(Fixed &, Fixed &);
};

std::ostream& operator<<(std::ostream& os, const Fixed &);

#endif