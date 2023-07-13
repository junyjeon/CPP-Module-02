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
	Fixed tmp = *this;
	++*this;
	return (tmp);
}

Fixed Fixed::operator--(int iInt) {
	Fixed tmp = *this;
	--*this;
	return (tmp);
}

Fixed Fixed::min(const Fixed &left, const Fixed &right) {
	return (left.toFloat() < right.toFloat() ? left : right);
}

Fixed Fixed::min(const int left, const int right) {
	return (left < right ? left : right);
}

Fixed Fixed::max(const Fixed &left, const Fixed &right) {
	return (left.toFloat() < right.toFloat() ? right : left);
}

Fixed Fixed::max(const int left, const int right) {
	return (left < right ? right : left);
}

std::ostream& operator<<(std::ostream& os, const Fixed &other) {
	os << other.toFloat();
	return os;
}

// int a, b, c;

// c = a.operator+(b);
// 증감 연산자 안먹음
// float선언 이상함