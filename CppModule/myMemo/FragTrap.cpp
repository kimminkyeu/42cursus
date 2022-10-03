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
	std::cout << "FragTrap std::string name - Constructor called.  =>  ";
	std::cout << "name:" <<this->_name << "  hp:" << this->_hitPoint << "  ep:" << this->_energyPoint << "  damage:" << this->_attackDamage << "\n";

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
