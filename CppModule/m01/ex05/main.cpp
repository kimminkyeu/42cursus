#include "Harl.hpp"

int main(void)
{
	Harl machine;

	machine.complain("DEBUG");
	machine.complain("INFO");
	machine.complain("WARNING");
	machine.complain("ERROR");
	machine.complain("NO_TYPE");

	return (0);
}
