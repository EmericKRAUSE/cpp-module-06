#include "Serializer.hpp"

//	####################
//	Constructor & Destructor
Serializer::Serializer()
{
	std::cout	<< "Default "
				<< YEL << "constructor" << RESET
				<< " called"
				<< std::endl;
}

Serializer::Serializer(const Serializer &obj)
{
	(void)obj;
	std::cout	<< "Copy "
				<< YEL << "constructor" << RESET
				<< " called"
				<< std::endl;
}

Serializer::~Serializer()
{
	std::cout	<< "Default "
				<< MAG << "destructor" << RESET
				<< " called"
				<< std::endl;
}

//	####################
//	Operator overload
Serializer &Serializer::operator=(const Serializer &obj)
{
	(void)obj;
	return (*this);
}

//	####################
//	Methodes
uintptr_t Serializer::serialize(Data *ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data* Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}