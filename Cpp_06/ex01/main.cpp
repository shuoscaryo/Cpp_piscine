#include "Serializer.hpp"
#define PURPLE "\033[1;35m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

int main()
{
	Data data;
	uintptr_t ptr1;
	Data *ptr2;

	std::cout << YELLOW "&data: " RESET << &data << std::endl; 
	ptr1 = Serializer::serialize(&data);
	std::cout << YELLOW "serialized: " RESET << ptr1 << std::endl; 
	ptr2 = Serializer::deserialize(ptr1);
	std::cout << YELLOW "deserialized: " RESET << ptr2 << std::endl; 
	return 0;
}