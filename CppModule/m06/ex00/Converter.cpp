#include "Converter.hpp"

Converter::Converter()
	:_valueBits(0), _precision(1) {}

Converter::~Converter()
{}

Converter::Converter(const Converter& converter)
{
	(*this) = converter;
}


Converter& Converter::operator= (const Converter& converter)
{
	this->_valueBits = converter._valueBits;
	return (*this);
}

int clamp(int val, int min, int max)
{
	if (val <= min)
		return min;
	else if (val >= max)
		return max;
	else
		return val;
}

static int getPrecision(const std::string& str)
{
	bool hasDot = false;
	int precision = 0;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == '.')
			hasDot = true;
		else
		{
			if (hasDot == true)
				precision++;
			if (str[i] == 'f')
				precision--;
		}
	}
	return (precision == 0 ? 1 : precision); // if precision is 0, return 1. else, return original val.
}

Converter::Converter(const std::string &str)
	:_valueBits(0), _precision(1)
{
	long long tmp = 0;

	switch (this->_getActualType(str))
	{
	case CHAR:
		this->_actualTypeInfo = CHAR;
		this->_valueChar = std::atoi(str.c_str());
		break;
	case INT:
		this->_actualTypeInfo = INT;
		tmp = std::atol(str.c_str());
		if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
			this->_actualTypeInfo = INT_OVERFLOW;
		else
			this->_valueInt = tmp;
		break;
	case FLOAT:
		this->_actualTypeInfo = FLOAT;
		this->_valueFloat = std::atof(str.c_str());
		this->_precision = getPrecision(str);
		break;
	case DOUBLE:
		this->_actualTypeInfo = DOUBLE;
		this->_valueDouble = std::atof(str.c_str());
		this->_precision = getPrecision(str);
		break;
	case INFINITE_NEGATIVE:
		this->_actualTypeInfo = INFINITE_NEGATIVE;
		break;
	case INFINITE_POSITIVE:
		this->_actualTypeInfo = INFINITE_POSITIVE;
		break;
	default /* IMPOSSIBLE */:
		this->_actualTypeInfo = IMPOSSIBLE;
		break;
	}

}

// helper
static bool isOnlyNumber(const std::string& str)
{
	for (int i = 0; i < str.length(); i++)
	{
		if (!(std::isdigit(str[i])) && !(str[i] == 'f') && !(str[i] == '.'))
			return (false);
	}
	return (true);
}


t_type	Converter::_getActualType(const std::string& str)
{
	// if has '.' in literal. ex) 2.0, 2.
	if (str.find('.', 0) != std::string::npos)
	{
		if (*(str.end() - 1) == 'f')
			return (FLOAT);
		else
			return (DOUBLE);
	}
	// if c --> data is char
	else if (str.length() == 1 && std::isalpha(str[0]))
	{
		return (CHAR);
	}
	// if 42, only number included (no string)
	else if (isOnlyNumber(str))
	{
		return (INT);
	}
	else if (str == "-inff" || str == "-inf")
	{
		return (INFINITE_NEGATIVE);
	}
	else if (str == "+inff" || str == "+inf")
	{
		return (INFINITE_POSITIVE);
	}
	else
		return (IMPOSSIBLE);
}

static void	printChar(char c)
{
	if (!std::isprint(c))
		std::cout << "Non displayable\n";
	else
		std::cout << '\'' << c << '\'' << std::endl;
}

// -------------------------------------------------------------
void Converter::printToChar()
{
	std::cout << "char: ";

	switch (_actualTypeInfo)
	{
	case CHAR:
		printChar(static_cast<char>(this->_valueChar));
		break;
	case INT:
		printChar(static_cast<char>(this->_valueInt));
		break;
	case FLOAT:
		printChar(static_cast<char>(this->_valueFloat));
		break;
	case DOUBLE:
		printChar(static_cast<char>(this->_valueDouble));
		break;
	default:
		std::cout << "impossible\n";
		break;
	}
}

void Converter::printToInt()
{
	std::cout << "int: ";

	long long tmp = 0;
	switch (_actualTypeInfo)
	{
	case CHAR:
		std::cout << static_cast<int>(this->_valueChar) << "\n";
		break;
	case INT:
		std::cout << static_cast<int>(this->_valueInt) << "\n";
		break;
	case FLOAT:
		tmp = static_cast<long long>(this->_valueFloat);
		if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(this->_valueFloat) << "\n";
		break;
	case DOUBLE:
		tmp = static_cast<long long>(this->_valueDouble);
		if (tmp > std::numeric_limits<int>::max() || tmp < std::numeric_limits<int>::min())
			std::cout << "impossible\n";
		else
			std::cout << static_cast<int>(this->_valueDouble) << "\n";
		break;
	default:
		std::cout << "impossible\n";
		break;
	}
}

void Converter::printToFloat()
{
	std::cout << "float: ";

	int new_precision = _precision;
	if (std::numeric_limits<float>::digits10 < _precision)
		new_precision = std::numeric_limits<float>::digits10;

	switch (_actualTypeInfo)
	{
	case CHAR:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<float>(this->_valueChar) << "f" << std::endl;
		break;
	case INT:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<float>(this->_valueInt) << "f" << std::endl;
		break;
	case FLOAT:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<float>(this->_valueFloat) << "f" << std::endl;
		break;
	case DOUBLE:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<float>(this->_valueDouble) << "f" << std::endl;
		break;
	case INFINITE_NEGATIVE:
		std::cout << "-inff\n";
		break;
	case INFINITE_POSITIVE:
		std::cout << "+inff\n";
		break;
	default:
		std::cout << "nanf\n";
		break;
	}
}

void Converter::printToDouble()
{
	std::cout << "double: ";

	int new_precision = _precision;
	if (std::numeric_limits<double>::digits10 < _precision)
		new_precision = std::numeric_limits<double>::digits10;

	switch (_actualTypeInfo)
	{
	case CHAR:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<double>(this->_valueChar) << std::endl;
		break;
	case INT:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<double>(this->_valueInt) << std::endl;
		break;
	case FLOAT:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<double>(this->_valueFloat) << std::endl;
		break;
	case DOUBLE:
		std::cout << std::fixed << std::setprecision(new_precision) << static_cast<double>(this->_valueDouble) << std::endl;
		break;
	case INFINITE_NEGATIVE:
		std::cout << "-inf\n";
		break;
	case INFINITE_POSITIVE:
		std::cout << "+inf\n";
		break;
	default:
		std::cout << "nan\n";
		break;
	}
}
