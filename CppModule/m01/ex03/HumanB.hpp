
#pragma once
#ifndef HUMAN_B_H
# define HUMAN_B_H

#include <iostream>
#include "Weapon.hpp"

class HumanB {

private:
	std::string _name;
	Weapon*		_weapon;

public:
	HumanB(const std::string& name);

	void	attack(void) const;
	void	setWeapon(const Weapon& weapon);

};

#endif /** HUMAN_B */
