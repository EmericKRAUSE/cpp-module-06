#include "ScalarConverter.hpp"
#include "../colors.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout	<< RED "Error: " << RESET
					<< "Arguments need to be 2"
					<< std::endl;
		return (0);
	}
	ScalarConverter::convert(argv[1]);
}