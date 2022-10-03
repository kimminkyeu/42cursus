#include "Converter.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
		return (1);

	Converter converter(av[1]);


	converter.printToChar();
	converter.printToInt();
	converter.printToFloat();
	converter.printToDouble();

	return (0);
}
