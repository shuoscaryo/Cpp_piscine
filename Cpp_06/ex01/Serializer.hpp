#pragma once
#include <iostream>
#include <stdint.h>

typedef struct 
{
	int number;
	char letter;
	float *pointer;
} Data;

class Serializer
{
	public:
		~Serializer(void);
		static uintptr_t serialize(Data *ptr);
		static Data *deserialize(uintptr_t raw);
	protected:
	private:
		Serializer & operator=(const Serializer & rhs);
		Serializer(const Serializer & src);
		Serializer(void);
};
