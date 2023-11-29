#include "Serializer.hpp"

Serializer::Serializer(void){}

Serializer::Serializer(const Serializer & src)
{
	*this = src;
}

Serializer::~Serializer(void)
{}

Serializer &Serializer::operator=(const Serializer &rhs)
{
	if (this != &rhs)
	{
		// copy
	}
	return (*this);
}

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data *Serializer::deserialize(uintptr_t raw)
{
	return reinterpret_cast<Data *>(raw); 
}