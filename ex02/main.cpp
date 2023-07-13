#include "Fixed.hpp"

int main(void)
{
	Fixed a(5);
	Fixed b(4);
	Fixed c;

	// std::cout << std::endl;
	// std::cout << '1' << std::endl;
	// c = a > b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '2' << std::endl;
	// c = a < b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '3' << std::endl;
	// c = a >= b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '4' << std::endl;
	// c = a <= b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '5' << std::endl;
	// c = a == b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '+' << std::endl;
	// c = a + b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '-' << std::endl;
	// c = a - b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '*' << std::endl;
	// c = a * b;
	// std::cout << c << std::endl;

	// std::cout << std::endl;
	// std::cout << '/' << std::endl;
	// c = a / b;
	// std::cout << c << std::endl;

	std::cout << std::endl;
	std::cout << '1' << std::endl;
	++a;
	std::cout << c << std::endl;

	std::cout << std::endl;
	std::cout << '2' << std::endl;
	a++;
	std::cout << c << std::endl;

	std::cout << std::endl;
	std::cout << '3' << std::endl;
	--a;
	std::cout << c << std::endl;

	std::cout << std::endl;
	std::cout << '4' << std::endl;
	a--;
	std::cout << c << std::endl;

	// Fixed const b(10);
	// Fixed const c(42.42f);
	// Fixed const d(b);

	// a = Fixed(1234.4321f);

	// std::cout << "a is " << a << std::endl;
	// std::cout << "b is " << b << std::endl;
	// std::cout << "c is " << c << std::endl;
	// std::cout << "d is " << d << std::endl;

	// std::cout << "a is " << a.toInt() << " as integer" << std::endl;
	// std::cout << "b is " << b.toInt() << " as integer" << std::endl;
	// std::cout << "c is " << c.toInt() << " as integer" << std::endl;
	// std::cout << "d is " << d.toInt() << " as integer" << std::endl;

	return 0;
}
