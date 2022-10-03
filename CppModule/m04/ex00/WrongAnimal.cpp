#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
	:_type("Anonymous")
{
	std::cout << "WrongAnimal default constructor called\n";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& animal)
	:_type(animal._type)
{
	std::cout << "WrongAnimal copy constructor called\n";
}

WrongAnimal& WrongAnimal::operator= (const WrongAnimal& animal)
{
	this->_type = animal._type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << _type << ": \"wooops! something is wrong!\"\n";
}

std::string WrongAnimal::getType() const
{
	return _type;
}
