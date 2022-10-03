
#pragma once
#ifndef HUMAN_A_H
# define HUMAN_A_H

#include <iostream>
#include "Weapon.hpp"

class HumanA {

private:
	std::string _name;
	Weapon*		_weapon;

public:
	// HumanA(void){};
	HumanA(const std::string& name, const Weapon& weapon);

	void	attack(void) const;
	void	setWeapon(const Weapon& weapon);

};

#endif /** HUMAN_A */
