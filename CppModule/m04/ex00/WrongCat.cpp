#include "WrongCat.hpp"

WrongCat::WrongCat()
	:WrongAnimal()
{
	this->_type = "WrongCat";
	std::cout << "WrongCat default constructor called\n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat& animal)
	:WrongAnimal(animal)
{
	std::cout << "WrongCat copy constructor called\n";
}

WrongCat& WrongCat::operator= (const WrongCat& animal)
{
	WrongAnimal::operator=(animal);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << _type << ": \"woops! something is wrong with meow!\"\n";
}
