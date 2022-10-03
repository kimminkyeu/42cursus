#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap a("A");
	std::cout << std::endl;
	a.whoAmI();
	std::cout << std::endl;


	DiamondTrap b("B");
	std::cout << std::endl;
	DiamondTrap c("C");
	std::cout << std::endl;


	std::cout << std::endl;
	a.attack("B");
	b.takeDamage(a.getAttackDamage());
	std::cout << std::endl;
	b.highFiveGuys();
	b.guardGate();
	std::cout << std::endl;
	b.attack("A");
	a.takeDamage(b.getAttackDamage());
	std::cout << std::endl;
	c.attack("B");
	b.takeDamage(c.getAttackDamage());
	std::cout << std::endl;
	b.ScavTrap::beRepaired(25);
	std::cout << std::endl;
	a.ScavTrap::beRepaired(25);
	std::cout << std::endl;
	a.highFiveGuys();
	a.guardGate();
	std::cout << std::endl;

	DiamondTrap test_with_name("Test");
	std::cout << std::endl;
	test_with_name.whoAmI();
	std::cout << std::endl;
	// DiamondTrap test_without_name{}; // because DiamondTrap name() 은 함수인지 생성자인지 컴파일러가 구분 못함.
	// --> cpp 98에선 사용 못하는 기능인 듯?
	std::cout << std::endl;
	test_with_name.whoAmI();
	std::cout << std::endl;
	test_with_name = b;
	test_with_name.whoAmI();
	std::cout << std::endl;



	return (0);
}
