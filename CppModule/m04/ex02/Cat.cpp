#include "Cat.hpp"

Cat::Cat()
	:Animal()
{
	std::cout << "Cat default constructor called\n";
	_brain = new Brain();
	_brain->ideas[0] = "cat's first idea";
	_brain->ideas[1] = "cat's second idea";
	this->_type = "Cat";
}

Cat::Cat(const std::string& idea)
	:Animal()
{
	std::cout << "Cat std::string idea constructor called\n";
	_brain = new Brain();
	_brain->ideas[0] = idea;
	this->_type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete _brain;
}

Cat::Cat(const Cat& animal)
	:Animal(animal)
{
	std::cout << "Cat copy constructor called\n";
	_brain = new Brain(*animal._brain);
}

Cat& Cat::operator= (const Cat& animal)
{
	Animal::operator=(animal);
	// deep copy brain

	*_brain = *animal._brain;
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << _type << ": \"meow~\" => ";
	std::cout << "Translating... \"" << _brain->ideas[0] << "\"\n";
}

void	Cat::changeMemory(const std::string& idea)
{
	std::cout << "Chainging cat memory...\n";
	this->_brain->ideas[0] = idea;
}
