#pragma once
#ifndef RABBIT_HPP
# define RABBIT_HPP

#include <string>
#include "AAnimal.hpp"

class Rabbit : public AAnimal {

private:

public:
	Rabbit();
	Rabbit& operator= (const Rabbit& animal);
	Rabbit(const Rabbit& animal);

	virtual ~Rabbit() /* override (C++11) */;
	virtual void makeSound() const /* override (C++11) */;
};




#endif // Cat.hpp
