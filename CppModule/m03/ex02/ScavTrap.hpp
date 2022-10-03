#pragma once
#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {

private:


public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& trap);
	ScavTrap& operator= (const ScavTrap& trap);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
	void 	guardGate() const;
};



#endif // ScavTrap.hpp
