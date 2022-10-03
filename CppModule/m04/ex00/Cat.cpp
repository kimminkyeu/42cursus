#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called\n";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat& animal)
	:Animal(animal)
{
	std::cout << "Cat copy constructor called\n";
}

Cat& Cat::operator= (const Cat& animal)
{
	Animal::operator=(animal);
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << _type << ": \"meow~\"\n";
}
