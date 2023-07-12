#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(int iInt) : value(iInt << bits) {}

Fixed::Fixed(float fFloat) : value(static_cast<int>(fFloat) << bits) {}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw){
	std::cout << "setRawBits member function called" << std::endl;
	value = raw;
}

float Fixed::toFloat(void) const {
	return static_cast<float>(value / (1 << bits));
}

int Fixed::toInt(void) const {
	return value >> bits;
}

std::ostream& operator<<(std::ostream& os, const Fixed &other) {
	os << other.toFloat();
	return os;
}
