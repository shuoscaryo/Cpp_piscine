#include <iostream>
#include "Fixed.hpp"

int main(void)
{
	{
		Fixed a;
		Fixed b(a);
		Fixed c;

		c = b;

		std::cout << a.getRawBits() << std::endl;
		std::cout << b.getRawBits() << std::endl;
		std::cout << c.getRawBits() << std::endl;
	}
	std::cout<< "======EXTRA TEST=========" << std::endl;
	{
		Fixed a;

		a.setRawBits(54);
		std::cout << a.getRawBits() << std::endl;
	}

	return (0);
}