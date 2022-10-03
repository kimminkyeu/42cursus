#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include "Helper.hpp"

class ClapTrap{

private:
	std::string 	_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

public:
	ClapTrap();
	ClapTrap(const ClapTrap& trap);
	~ClapTrap();
	ClapTrap& operator= (const ClapTrap& trap);

	ClapTrap(const std::string& name);
	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	std::string		getName() const;
	unsigned int	getHitPoint() const;
	unsigned int	getEnergyPoint() const;
	unsigned int	getAttackDamage() const;

	void			setName(const std::string& name);
	void			setHitPoint(const unsigned int& val);
	void			setEnergyPoint(const unsigned int& val);
	void			setAttackDamage(const unsigned int& val);


};


#endif // ClapTrap.hpp
