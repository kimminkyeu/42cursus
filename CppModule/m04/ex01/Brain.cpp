#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain& brain)
{
	(*this) = brain;
}

Brain& Brain::operator= (const Brain& brain)
{
	// copy brain's first memory data.
	this->ideas[0] = brain.ideas[0];
	// std::memcpy(this->ideas, brain.ideas, sizeof(ideas)); // WARN:  std::string error
	return (*this);
}
