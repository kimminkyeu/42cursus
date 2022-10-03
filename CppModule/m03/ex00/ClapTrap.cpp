#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
 : _name("no_Name"), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "Default Constructor called\n";
}

ClapTrap::ClapTrap(const std::string& name)
	:_name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0)
{
	std::cout << "std::string name - Constructor called\n";
}

ClapTrap::ClapTrap(const ClapTrap& trap)
{
	std::cout << "Copy Constructor called\n";
	*this = trap;
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap& ClapTrap::operator= (const ClapTrap& trap)
{
	this->setName(trap.getName());
	this->setAttackDamage(trap.getEnergyPoint());
	this->setEnergyPoint(trap.getEnergyPoint());
	this->setHitPoint(trap.getHitPoint());
	return (*this);
}

std::string ClapTrap::getName() const {return _name;}
unsigned int ClapTrap::getHitPoint() const {return _hitPoint;}
unsigned int ClapTrap::getEnergyPoint() const {return _energyPoint;}
unsigned int ClapTrap::getAttackDamage() const {return _attackDamage;}
void ClapTrap::setName(const std::string &name) {_name = name;}
void ClapTrap::setHitPoint(const unsigned int &val) {_hitPoint = val;}
void ClapTrap::setEnergyPoint(const unsigned int &val) {_energyPoint = val;}
void ClapTrap::setAttackDamage(const unsigned int &val) {_attackDamage = val;}

void ClapTrap::attack(const std::string& target)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage! --> ";
		_energyPoint--;
	} else {
		std::cout << _name << " can't attack --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << _name << " takes " << amount << " damage --> ";
		_hitPoint = Helper::clamp(_hitPoint - amount, 0, 10);
	} else {
		std::cout << _name << " can't take damage --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_hitPoint > 0 && _energyPoint > 0) {
		std::cout << _name << " repaired " << amount << " hit point --> ";
		_hitPoint = Helper::clamp(_hitPoint + amount, 0, 10);
		_energyPoint--;
	} else {
		std::cout << _name << " can't be repaired --> ";
	}
	std::cout << _name << ": hp(" << _hitPoint << ") ep(" << _energyPoint << ")\n";
}
