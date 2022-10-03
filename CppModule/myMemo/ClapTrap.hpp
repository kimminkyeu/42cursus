#pragma once
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <string>
#include <iostream>
#include "Helper.hpp"

class ClapTrap{

// private:
protected:
	std::string 	_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

	const unsigned int	_MaxHP = 0;

public:
	ClapTrap();
	~ClapTrap();
	ClapTrap(const ClapTrap& trap); // NOTE:  used explicit keyword for forbidding auto casting?
	ClapTrap(const std::string& name);
	ClapTrap& operator= (const ClapTrap& trap);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	ClapTrap(const std::string& name, const unsigned int& hp, const unsigned int& ep, const unsigned int& damage);

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
