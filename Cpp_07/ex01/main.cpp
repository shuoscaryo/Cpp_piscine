#include "iter.hpp"
#include <string>
#include <iostream>

#define PURPLE "\033[1;35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

class Obj
{
	private:
		std::string name;
		float number;
	public:
		Obj();
		Obj(const Obj &obj);
		~Obj();
		Obj &operator=(const Obj &obj);

		static void iter(size_t i, Obj &obj);
		const std::string &getName() const;
		float getNumber() const;
};

Obj::Obj():name(""),number(0){}
Obj::Obj(const Obj &obj){*this = obj;}
Obj::~Obj(){}
Obj &Obj::operator=(const Obj &obj)
{
	if (&obj != this)
	{
		name = obj.name;
		number = obj.number;
	}
	return *this;
}
const std::string &Obj::getName() const{return (name);}
float Obj::getNumber() const{return (number);}

void addindex(size_t i, std::string &s)
{
	s += "0123456789"[i % 10];
}

void square(size_t i, float &f)
{
	f = i * i;
}

void Obj::iter(size_t i, Obj &obj)
{
	addindex(i,obj.name);
	square(i,obj.number);
}

int main()
{
	size_t len= 5;

	std::cout << YELLOW "Creating a string array of size " << len << RESET << std::endl;
	std::string *my_str = new std::string[len];
	for (size_t i = 0; i < len; i++)
		std::cout << "str["<<i<<"] = \"" << my_str[i] << "\""<<std::endl;
	std::cout << std::endl;
	std::cout << YELLOW "Using iter with addindex" RESET << std::endl;
	iter(my_str, len, addindex);
	for (size_t i = 0; i < len; i++)
		std::cout << "str["<<i<<"] = \"" << my_str[i] << "\""<<std::endl;
	delete [] my_str;
	std::cout << std::endl;

	std::cout << YELLOW "Trying iter on NULL pointer" RESET << std::endl;
	my_str = NULL;
	iter(my_str, len, addindex);
	std::cout << std::endl;


	std::cout << YELLOW "Creating obj class array of size " << len << RESET << std::endl;
	Obj *obj = new Obj[len];
	for (size_t i = 0; i < len; i++)
		std::cout << "obj["<<i<<"] = name=\"" << obj[i].getName() << "\", number="<< obj[i].getNumber() << std::endl;
	std::cout << std::endl;
	std::cout << YELLOW "Using iter with obj::iter" RESET << std::endl;
	iter(obj, len, Obj::iter);
	for (size_t i = 0; i < len; i++)
		std::cout << "obj["<<i<<"] = name=\"" << obj[i].getName() << "\", number="<< obj[i].getNumber() << std::endl;
	delete [] obj;
}