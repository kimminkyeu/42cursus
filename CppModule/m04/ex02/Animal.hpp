#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class Animal {

protected:
	std::string _type;


public:
	Animal();

	virtual ~Animal();

	Animal(const Animal& animal);
	Animal& operator= (const Animal& animal);
	std::string getType() const;

	virtual void makeSound() const;  // Animal pointer를 써도 cat의 makeSound 호출하기.
};




#endif // Animal.hpp
