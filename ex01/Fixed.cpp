#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int iInt) : value(iInt << bits) {
	std::cout  << "Int constructor called" << std::endl;
}

Fixed::Fixed(float fFloat) : value(roundf(fFloat * (1 << bits))) {
	std::cout  << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	value = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const{
	return value;
}

void Fixed::setRawBits(int const raw){
	value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(value) / static_cast<float>(1 << bits);
}

int Fixed::toInt(void) const {
	return value / (1 << bits);
}

std::ostream& operator<<(std::ostream& os, const Fixed &other) {
	os << other.toFloat();
	return os;
}
