#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called\n";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog& animal)
	:Animal(animal)
{
	std::cout << "Dog copy constructor called\n";
}

Dog& Dog::operator= (const Dog& animal)
{
	Animal::operator=(animal);
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << _type << ": \"Bark! Bark!\"\n";
}

// std::string Dog::getType()
// {
	// return _type;
// }
