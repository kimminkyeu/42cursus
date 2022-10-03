#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("A");
	a.setAttackDamage(3);
	ClapTrap	b("B");
	b.setAttackDamage(12);
	ClapTrap	c("C");
	c.setAttackDamage(2);

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
	a.beRepaired(25);
	std::cout << std::endl;
	return (0);
}
