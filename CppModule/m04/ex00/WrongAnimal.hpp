#pragma once
#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal {

protected:
	std::string _type;


public:
	WrongAnimal();

	~WrongAnimal();

	WrongAnimal(const WrongAnimal& animal);
	WrongAnimal& operator= (const WrongAnimal& animal);

	void makeSound() const;
	std::string getType() const;
};




#endif // WrongAnimal.hpp
