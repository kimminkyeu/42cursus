#include "Animal.hpp"

Animal::Animal()
	:_type("Anonymous")
{
	std::cout << "Animal default constructor called\n";
}

Animal::~Animal()
{
	std::cout << "Animal Destructor called\n";
}

Animal::Animal(const Animal& animal)
	:_type(animal._type)
{
	std::cout << "Animal copy constructor called\n";
}

Animal& Animal::operator= (const Animal& animal)
{
	this->_type = animal._type;
	return (*this);
}

void Animal::makeSound() const
{
	std::cout << _type << ": \"...?\"\n";
}

std::string Animal::getType() const
{
	return _type;
}
