#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"
// #include "ClapTrap.hpp"
// #include "FragTrap.hpp"
// #include "ScavTrap.hpp"

/**
 * Name : from ClapTrap + _clap_name.
 * HitPoint : from FragTrap, = 100
 * EnergyPoint : from ScavTrap, = 50
 * Attack Damage : from FragTrap, = 30
 * attack() : from ScavTrap. --> use using
 */

DiamondTrap::DiamondTrap()
	:ClapTrap("NoName_clap_name"), _name("NoName")
{
	// ClapTrap::_name += "_clap_name";
	_energyPoint = 50;
	_hitPoint = 100;
	_attackDamage = 30;
	// _energyPoint = ScavTrap::_energyPoint;
	std::cout << "DiamondTrap default constructor => ";
	std::cout << "name:" <<this->_name << "  hp:" << this->_hitPoint << "  ep:" << this->_energyPoint << "  damage:" << this->_attackDamage << "\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap& trap)
	// : ClapTrap(trap._name + "_clap_name"), ScavTrap(trap), FragTrap(trap), _name(trap._name)
	: ClapTrap(trap._name + "_clap_name")
{
	_name = trap._name;
	_energyPoint = 50;
	_hitPoint = 100;
	_attackDamage = 30;
	// _energyPoint = ScavTrap::_energyPoint;
	// _energyPoint = ScavTrap::_energyPoint;
	// _attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap copy constructor => ";
	std::cout << "name:" <<this->_name << "  hp:" << this->_hitPoint << "  ep:" << this->_energyPoint << "  damage:" << this->_attackDamage << "\n";
}

DiamondTrap::DiamondTrap(const std::string& name)
	// : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
	: ClapTrap(name + "_clap_name")
{
	_name = name;
	_energyPoint = 50;
	_hitPoint = 100;
	_attackDamage = 30;
	// _energyPoint = ScavTrap::_energyPoint;
	// _attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap std::string name constructor => ";
	std::cout << "name:" <<this->_name << "  hp:" << this->_hitPoint << "  ep:" << this->_energyPoint << "  damage:" << this->_attackDamage << "\n";
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor\n";
}

DiamondTrap& DiamondTrap::operator= (const DiamondTrap& trap)
{
	_name = trap._name;
	ClapTrap::_name = trap._name + "_clap_name";
    _hitPoint = trap._hitPoint;
    _energyPoint = trap._energyPoint;
    _attackDamage = trap._attackDamage;
    std::cout << "DiamondTrap copy assignment operator => ";
	std::cout << "name:" <<this->_name << "  hp:" << this->_hitPoint << "  ep:" << this->_energyPoint << "  damage:" << this->_attackDamage << "\n";
    return (*this);
}

void DiamondTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "DiamondTrap " << _name << " takes " << amount << " damage --> ";
		_hitPoint = Helper::clamp(_hitPoint - amount, 0, 100);
	} else {
		std::cout << _name << " can't take damage --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void	DiamondTrap::whoAmI() const
{
	std::cout << "WhoAmI() => Diamond name:" << _name << "\t\tClapTrap name:" << ClapTrap::_name << "\n";
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << "DiamondTrap " << _name << " repaired " << amount << " hit point --> ";
		_hitPoint = Helper::clamp(_hitPoint + amount, 0, 100);
		_energyPoint--;
	} else {
		std::cout << _name << " can't be repaired --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}
