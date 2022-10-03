#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

ScavTrap::ScavTrap()
	:ClapTrap("no_Name", 100, 50, 20) // ? :c++11 기능 아닌지?
{
	std::cout << "ScavTrap Default Constructor called\n";
	// _hitPoint = 100;
	// _energyPoint = 50;
	// _attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& trap)
	// : ClapTrap(trap) --> simpler version
	:ClapTrap(static_cast<ClapTrap>(trap))
{
	std::cout << "ScavTrap Copy Constructor called\n";
}

ScavTrap::ScavTrap(const std::string& name)
	:ClapTrap(name, 100, 50, 20)
{
	std::cout << "ScavTrap std::string name - Constructor called\n";
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

ScavTrap& ScavTrap::operator= (const ScavTrap& trap)
{
	std::cout << "ScavTrap copy assignment operator called\n";
	this->ClapTrap::operator=(trap); // call ClapTrap's copy assignment operator.
	// static_cast<ClapTrap&>(*this) = trap;
	return (*this);
}

void	ScavTrap::guardGate() const
{
	if (_hitPoint > 0) {
		std::cout << this->_name << "is guarding gate.\n";
	} else {
		std::cout << this->_name << " can't guard gate because hp is 0\n";
	}
}

void ScavTrap::attack(const std::string& target)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "ScavTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! --> ";
		_energyPoint--;
	} else {
		std::cout << _name << " can't attack --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void ScavTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "ScavTrap " << _name << " takes " << amount << " damage --> ";
		_hitPoint = Helper::clamp(_hitPoint - amount, 0, 100);
	} else {
		std::cout << _name << " can't take damage --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void ScavTrap::beRepaired(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "ScavTrap " << _name << " repaired " << amount << " hit point --> ";
		_hitPoint = Helper::clamp(_hitPoint + amount, 0, 100);
		_energyPoint--;
	} else {
		std::cout << _name << " can't be repaired --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

