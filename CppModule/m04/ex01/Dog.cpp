#include "Dog.hpp"

Dog::Dog()
	:Animal()
{
	std::cout << "Dog default constructor called\n";
	_brain = new Brain();
	_brain->ideas[0] = "dog's first idea";
	_brain->ideas[1] = "dog's second idea";
	this->_type = "Dog";
}

Dog::Dog(const std::string& idea)
	:Animal()
{
	std::cout << "Dog std::string idea constructor called\n";
	_brain = new Brain();
	_brain->ideas[0] = idea;
	this->_type = "Dog";
}


Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
	delete _brain;
}

Dog::Dog(const Dog& animal)
	:Animal(animal)
{
	std::cout << "Dog copy constructor called\n";
	_brain = new Brain(*animal._brain);
}

Dog& Dog::operator= (const Dog& animal)
{
	Animal::operator=(animal);
	*_brain = *animal._brain;
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << _type << ": \"Bark! Bark!\" => ";
	std::cout << "Translating... \"" << _brain->ideas[0] << "\"\n";
}

void	Dog::changeMemory(const std::string& idea)
{
	std::cout << "Chainging dog memory...\n";
	this->_brain->ideas[0] = idea;
}
