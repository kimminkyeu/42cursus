#include "Harl.hpp"

int main(int ac, char** av)
{
	if (ac != 2)
		return (EXIT_FAILURE);
	Harl(std::string(av[1]));
	return (EXIT_SUCCESS);
}
