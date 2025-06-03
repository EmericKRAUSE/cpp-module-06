#include "Serializer.hpp"

int main()
{
	Data		*data = new Data;
	Data		*data2 = NULL;
	uintptr_t	uintptr;

	data->name = "Bernard";
	data->age = 42;

	std::cout	<< GRN << "Before serialize: " << RESET << std::endl;

	std::cout	<< CYN << "Adress: " << RESET
				<< data
				<< std::endl;

	std::cout	<< CYN << "Name: " << RESET
				<< data->name
				<< std::endl;

	std::cout	<< CYN << "Age: " << RESET
				<< data->age
				<< std::endl;

	uintptr = Serializer::serialize(data);

	std::cout << uintptr << std::endl;
	data2 = Serializer::deserialize(uintptr);

	std::cout << GRN << "After serialize: " << RESET << std::endl;

	std::cout << CYN << "Adress: " << RESET
			  << data2
			  << std::endl;

	std::cout << CYN << "Name: " << RESET
			  << data2->name
			  << std::endl;

	std::cout << CYN << "Age: " << RESET
			  << data2->age
			  << std::endl;

	delete data;
	return (0);
}