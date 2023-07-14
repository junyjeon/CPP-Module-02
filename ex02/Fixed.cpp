#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
}

Fixed::~Fixed() {
}

Fixed::Fixed(int iInt) : value(iInt << bits) {}

Fixed::Fixed(float fFloat) : value(roundf(fFloat * (1 << bits))) {}

Fixed::Fixed(const Fixed &other) {
	*this = other;
}

int Fixed::getRawBits(void) const {
	return value;
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(value) / static_cast<float>(1 << bits);
}

int Fixed::toInt(void) const {
	return value >> bits;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this == &other)
		return *this;
	value = other.getRawBits();
	return *this;
}

/* bool */

bool Fixed::operator>(const Fixed &other) const {
	return value > other.value ? true : false;
}

bool Fixed::operator<(const Fixed &other) const {
	return value < other.value ? true : false;
}

bool Fixed::operator>=(const Fixed &other) const {
	return value >= other.value ? true : false;
}

bool Fixed::operator<=(const Fixed &other) const {
	return value <= other.value ? true : false;
}

bool Fixed::operator==(const Fixed &other) const {
	return value == other.value ? true : false;
}

bool Fixed::operator!=(const Fixed &other) const {
	return value != other.value ? true : false;
}

/* + - * / */

Fixed Fixed::operator+(const Fixed &other) const {
	return (Fixed(this->toFloat() + other.toFloat()));
	// return Fixed((value + other.value) / (1 << bits));
}

Fixed Fixed::operator-(const Fixed &other) const {
	return Fixed((value - other.value) / (1 << bits));
}

Fixed Fixed::operator*(const Fixed &other) const {
	return Fixed(value * other.value / (1 << bits * 2));
}

Fixed Fixed::operator/(const Fixed &other) const {
	if (other.value == 0)
	{
		std::cout << "" << std::endl;
		return 0;
	}
	return Fixed(value / other.value);
}

/* ++ -- */

Fixed &Fixed::operator++(void) {
	value += (1 << bits);
	return (*this);
}

const Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	operator++();
	return (tmp);
}

Fixed &Fixed::operator--(void) {
	value -= (1 << bits);
	return (*this);
}

const Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	operator--();
	return (tmp);
}

/* max min */

const Fixed &Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
	return (a < b ? a : b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b) {
	return (a > b ? a : b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
	return (a > b ? a : b);
}


std::ostream& operator<<(std::ostream& os, const Fixed &other) {
	os << other.toFloat();
	return os;
}