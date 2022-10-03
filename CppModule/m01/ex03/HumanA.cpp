#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, const Weapon& weapon)
{
	this->_name = name;
	// NOTE:  <const_cast> : de-const Weapon& temporally.
	this->_weapon = &const_cast<Weapon&>(weapon);
}

void	HumanA::attack(void) const
{
	std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanA::setWeapon(const Weapon& weapon)
{
	// NOTE:  <const_cast> : de-const Weapon& temporally.
	this->_weapon = &const_cast<Weapon&>(weapon);
	// same as Weapon* ptr = &weapon
}
