#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

protected:
	std::string _type;


public:
	Animal();
	~Animal();
	Animal(const Animal& animal);
	Animal& operator= (const Animal& animal);

	void makeSound() const;

	std::string getType() const;
};




#endif // Animal.hpp
