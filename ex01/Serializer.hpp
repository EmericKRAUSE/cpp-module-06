#pragma once

#include "../colors.hpp"
#include <string>
#include <iostream>
#include <stdint.h>

typedef struct Data
{
	std::string	name;
	int			age;
} 				Data;


class Serializer
{
	private:
		//	####################
		//	Constructor & Destructor
		Serializer();
		Serializer(const Serializer &obj);
		~Serializer();

		//	####################
		//	Operator overload
		Serializer &operator=(const Serializer &obj);
	public:
		//	####################
		//	Methodes
		static uintptr_t	serialize(Data *ptr);
		static Data			*deserialize(uintptr_t raw);
};