#pragma once
#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap {

private:

public:
	FragTrap();
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& trap);
	~FragTrap();
	FragTrap& operator= (const FragTrap& trap);

	void highFiveGuys();
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);



};

#endif
