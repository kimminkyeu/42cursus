#include "AAnimal.hpp"

AAnimal::AAnimal()
	:_type("Anonymous")
{
	std::cout << "Abstract Animal default constructor called\n";
}

AAnimal::~AAnimal()
{
	std::cout << "Abstract Animal Destructor called\n";
}

AAnimal::AAnimal(const AAnimal& animal)
	:_type(animal._type)
{
	std::cout << "Abstract Animal copy constructor called\n";
}

AAnimal& AAnimal::operator= (const AAnimal& animal)
{
	std::cout << "Abstract Animal copy assignment operator called\n";
	this->_type = animal._type;
	return (*this);
}

std::string AAnimal::getType() const
{
	return _type;
}

void AAnimal::makeSound() const
{
	std::cout << "no Sound\n";
}
