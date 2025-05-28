#pragma once

# include <iostream>
# include <string> 
# include <cstdlib>
# include <iomanip>

class ScalarConverter
{
	private:
		//	####################
		//	Constructor & Destructor
		ScalarConverter();
		ScalarConverter(const ScalarConverter &obj);
		~ScalarConverter();

		//	####################
		//	Operator overload
		ScalarConverter &operator=(const ScalarConverter &obj);
	public:

		//	####################
		//	Methodes
		static void convert(const std::string &toConvert);
};
