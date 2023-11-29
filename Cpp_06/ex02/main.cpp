#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "Base.hpp"
#include <cstdlib>

#define PURPLE "\033[1;35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

Base *generate()
{
	srand(time(NULL));
	int i = rand() % 3;

	switch (i)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		case 2:
			return new C;
	}
	return NULL;
}

void identify (Base *p)
{
	if (dynamic_cast<A*>(p))
		return (std::cout << "A"<<std::endl, void());
	if (dynamic_cast<B*>(p))
		return (std::cout << "B"<<std::endl, void());
	if (dynamic_cast<C*>(p))
		return (std::cout << "C"<<std::endl, void());
	std::cout << "Unknown type" << std::endl;
}

void identify (Base &p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		return (std::cout << "A"<<std::endl, void());
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<B&>(p);
		return (std::cout << "B"<<std::endl, void());
	}
	catch(...)
	{}
	try
	{
		(void)dynamic_cast<C&>(p);
		return (std::cout << "C"<<std::endl, void());
	}
	catch(...)
	{}
	std::cout << "Unknown type" << std::endl;
}

int main()
{
	std::cout << YELLOW "Generating random obj" RESET << std::endl;
	Base *obj = generate();
	std::cout << "\n";

	std::cout << YELLOW "Using identify with obj as pointer" RESET << std::endl;
	identify(obj);
	std::cout << "\n";
	std::cout << YELLOW "Using identify with obj as reference" RESET << std::endl;
	identify(*obj);
	std::cout << "\n";
	delete obj;

	std::cout << YELLOW "Using identify with NULL" RESET << std::endl;
	identify (NULL);
	std::cout << "\n";


	std::cout << YELLOW "Creating A,B,C,Base objects and checking their types" RESET << std::endl;
	A a;
	B b;
	C c;
	Base base;

	std::cout << YELLOW "Type of A: " RESET;
	identify(a);
	std::cout << YELLOW "Type of B: " RESET;
	identify(b);
	std::cout << YELLOW "Type of C: " RESET;
	identify(c);
	std::cout << YELLOW "Type of Base: " RESET;
	identify(base);

}