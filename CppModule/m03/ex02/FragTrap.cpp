#include "FragTrap.hpp"
#include "ClapTrap.hpp"

FragTrap::FragTrap()
	:ClapTrap("noName", 100, 100, 30)
{
	std::cout << "FragTrap Default Constructor called\n";
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

FragTrap::FragTrap(const FragTrap& trap)
	:ClapTrap(trap)
{
	std::cout << "FragTrap Copy Constructor called\n";
}

FragTrap::FragTrap(const std::string& name)
	:ClapTrap(name, 100, 100, 30)
{
	std::cout << "FragTrap std::string name - Constructor called\n";
}

FragTrap& FragTrap::operator= (const FragTrap& trap)
{
	// this->ClapTrap::operator=(static_cast<const ClapTrap&>(trap));
	std::cout << "FragTrap copy assignment operator called\n";
	this->ClapTrap::operator=(trap);
	return (*this);
}

void FragTrap::highFiveGuys()
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "FragTrap " << _name << " asks for a positive high-five\n";
	} else {
		std::cout << "FragTrap " << _name << " can't ask for a positive high-five\n";
	}
}

void FragTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "FragTrap " << _name << " takes " << amount << " damage --> ";
		_hitPoint = Helper::clamp(_hitPoint - amount, 0, 100);
	} else {
		std::cout << _name << " can't take damage --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void FragTrap::beRepaired(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "FragTrap " << _name << " repaired " << amount << " hit point --> ";
		_hitPoint = Helper::clamp(_hitPoint + amount, 0, 100);
		_energyPoint--;
	} else {
		std::cout << _name << " can't be repaired --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void FragTrap::attack(const std::string& target)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "FragTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! --> ";
		_energyPoint--;
	} else {
		std::cout << _name << " can't attack --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}
