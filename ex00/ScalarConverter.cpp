#include "ScalarConverter.hpp"
#include "../colors.hpp"

//	####################
//	Constructor & Destructor
ScalarConverter::ScalarConverter()
{
	std::cout	<< "Default "
				<< YEL << "constructor" << RESET
				<< " called"
				<< std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &obj)
{
	(void)obj;
	std::cout	<< "Copy "
				<< YEL << "constructor" << RESET
				<< " called"
				<< std::endl;
}

ScalarConverter::~ScalarConverter()
{
	std::cout	<< "Default "
				<< MAG << "destructor" << RESET
				<< " called"
				<< std::endl;
}

//	####################
//	Operator overload
ScalarConverter& ScalarConverter::operator=(const ScalarConverter &obj)
{
	(void)obj;
	return (*this);
}

//	####################
//	Methodes
bool	isSafeToConvertToInt(const std::string &toConvert)
{
	if (toConvert[0] == '+' || toConvert[0] == '-')
	{
		if (toConvert.length() > 11)
			return (0);
	}
	else if (toConvert.length() > 10)
		return (0);
	long	l = atol(toConvert.c_str());
	if (l > INT_MAX || l < INT_MIN)
		return (0);
	return (1);
}

int isChar(const std::string &str)
{
	if (str.length() != 1 || std::isdigit(str[0]))
		return (0);
	return (1);
}

int isFloat(const std::string &str)
{
	size_t	i = 0;
	bool	isDot = false;

	if (str.find('.') == std::string::npos || str[str.length() - 1] != 'f')
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (isDot)
				return (0);
			else
				isDot = true;
		}
		else if (i < str.length() - 1 && !std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	isDouble(const std::string &str)
{
	size_t	i = 0;
	bool	isDot = false;

	if (str.find('.') == std::string::npos)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (isDot)
				return (0);
			else
				isDot = true;
		}
		else if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	isInt(const std::string &str)
{
	size_t	i = 0;

	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (!std::isdigit(str[i]))
			return (0);
		i++;
	}
	return (isSafeToConvertToInt(str));
}

void	printChar(char c)
{
	std::cout << CYN << "char:   " << RESET;
	if (isprint(c))
		std::cout << "'" << c << "'" << std::endl;
	else
		std::cout << "non displayable" << std::endl;
}

void	printInt(int i)
{
	std::cout	<< CYN << "int:    " << RESET
				<< i << std::endl;
}

void	printFloat(float f)
{
	std::cout	<< CYN << "float:  " << RESET
				<< std::fixed << std::setprecision(1) << f << 'f' << std::endl;
}

void	printDouble(double d)
{
	std::cout	<< CYN << "double: " << RESET
				<< std::fixed << std::setprecision(1) << d << std::endl;
}

void ScalarConverter::convert(const std::string &toConvert)
{
	if (isChar(toConvert))
	{
		char	c = toConvert[0];
		printChar(c);
		printInt(static_cast <int> (c));
		printFloat(static_cast <float> (c));
		printDouble(static_cast <double> (c));
	}
	else if (isFloat(toConvert))
	{
		float	f = atof(toConvert.c_str());
		printChar(static_cast <char> (f));
		printInt(static_cast <int> (f));
		printFloat(f);
		printDouble(static_cast <double> (f));
	}
	else if (isDouble(toConvert))
	{
		double	d = atof(toConvert.c_str());
		printChar(static_cast <char> (d));
		printInt(static_cast <int> (d));
		printFloat(static_cast <float> (d));
		printDouble(d);
	}
	else if (isInt(toConvert))
	{
		int	i = atoi(toConvert.c_str());
		printChar(static_cast <char> (i));
		printInt(i);
		printFloat(static_cast <float> (i));
		printDouble(static_cast <double> (i));
	}
	else
	{
		std::cout	<< RED << "Error:" << RESET
					<< " wrong input"
					<< std::endl;
	}
}