#include "Rabbit.hpp"

Rabbit::Rabbit()
	:AAnimal()
{
	std::cout << "Rabbit default constructor called\n";
	this->_type = "Rabbit";
}

Rabbit::~Rabbit()
{
	std::cout << "Rabbit destructor called\n";
}

Rabbit::Rabbit(const Rabbit& animal)
	:AAnimal(animal)
{
	std::cout << "Rabbit copy constructor called\n";
}

Rabbit& Rabbit::operator= (const Rabbit& animal)
{
	AAnimal::operator=(animal);
	return (*this);
}

void Rabbit::makeSound() const
{
	std::cout << _type << ": \"rra bit~ ra bit~\" => ";
}
