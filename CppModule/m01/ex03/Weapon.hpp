
#pragma once
#ifndef WEAPON_H
# define WEAPON_H

#include <string>

class Weapon {

private:
	std::string _type;

public:
	Weapon(const std::string& type);

	const std::string&	getType(void) const; // const member!

	void	setType(const std::string& type);
};

#endif /** WEAPON_H */
