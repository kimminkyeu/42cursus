#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	a("A");
	ScavTrap	b("B");
	ScavTrap	c("C");


	std::cout << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	std::cout << std::endl;
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	std::cout << std::endl;
	c.attack("B");
	b.takeDamage(c.getAttackDamage());
	std::cout << std::endl;
	b.beRepaired(25);
	std::cout << std::endl;
	a.beRepaired(25);
	std::cout << std::endl;
	a.guardGate();
	std::cout << std::endl;
	return (0);
}
