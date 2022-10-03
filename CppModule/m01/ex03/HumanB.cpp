#include "HumanB.hpp"

HumanB::HumanB(const std::string& name)
	: _name(name), _weapon(NULL)
{}

void	HumanB::attack(void) const
{
	if (this->_weapon == NULL)
		std::cout << this->_name << " has no weapon" << std::endl;
	else
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
}

void	HumanB::setWeapon(const Weapon& weapon)
{
	// NOTE:  <const_cast> : de-const Weapon& temporally.
	this->_weapon = &const_cast<Weapon&>(weapon);
	// same as Weapon* ptr = &weapon
}
