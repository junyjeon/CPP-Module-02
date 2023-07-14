#include "Fixed.hpp"

Fixed::Fixed() : value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int iInt) : value(iInt << bits) {}

Fixed::Fixed(float fFloat) : value(roundf(fFloat * (1 << bits)) ) {}

Fixed::Fixed(const Fixed &other){
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

int Fixed::getRawBits(void) const {
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




Fixed &Fixed::operator=(const Fixed &other){
	std::cout << "Copy assignment operator called" << std::endl;
	value = other.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &other) const {
	return value > other.value ? true : false;
}

bool Fixed::operator<(const Fixed &other) const {
	return value < other.value ? true : false;
}

bool Fixed::operator>=(const Fixed &other) const {
	return value >= other.value ? true : false;
}

bool Fixed::operator<=(const Fixed &other) const{
	return value <= other.value ? true : false;
}

bool Fixed::operator==(const Fixed &other) const {
	return value == other.value ? true : false;
}

bool Fixed::operator!=(const Fixed &other) const {
	return value != other.value ? true : false;
}




Fixed Fixed::operator+(const Fixed &other) const {
	Fixed tmp;
	tmp.value = value + other.value;
	return tmp;
}

Fixed Fixed::operator-(const Fixed &other) const {
	Fixed tmp;
	tmp.value = value - other.value;
	return tmp;
}

Fixed Fixed::operator*(const Fixed &other) const {
	Fixed tmp;
	tmp.value = (this->toInt() * other.toInt()) * (1 << bits);
	return tmp;
}

Fixed Fixed::operator/(const Fixed &other) const {
	Fixed tmp;
	if ( == 0)
	{
		std::cout << // 에러
		return tmp;
	}
	tmp.value = (this->toInt() / other.toInt()) * (1 << bits);
	return tmp;
}




Fixed &Fixed::operator++(void) {
	value++;
	return (*this);
}

Fixed &Fixed::operator--(void) {
	value--;
	return (*this);
}

Fixed Fixed::operator++(int iInt) {
	Fixed tmp(*this);
	++*this;
	return (tmp);
}

Fixed Fixed::operator--(int iInt) {
	Fixed tmp = *this;
	--*this;
	return (tmp);
}




Fixed Fixed::min(const Fixed &a, const Fixed &b) {
	return (a < b ? a : b);
}

Fixed Fixed::min(const int a, const int b) {
	return (a < b ? a : b);
}

Fixed Fixed::max(const Fixed &a, const Fixed &b) {
	return (a < b ? b : a);
}

Fixed Fixed::max(const int a, const int b) {
	return (a < b ? b : a);
}

std::ostream& operator<<(std::ostream& os, const Fixed &other) {
	os << other.toFloat();
	return os;
}

// int a, b, c;

// c = a.operator+(b);
// 증감 연산자 안먹음
// float선언 이상함