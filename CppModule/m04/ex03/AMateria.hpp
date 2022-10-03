#pragma once
#ifndef AMATERIA_CPP
# define AMATERIA_CPP

#include <string>
#include "ICharacter.hpp"

class AMateria
{
protected:
	//[...]

public :

	AMateria(std::string const &type);
	// [...]

	std::string const &getType() const; //Returns the materia type

	virtual void use(ICharacter &target);

	virtual AMateria *clone() const = 0;

};

#endif // AMATERIA_CPP
