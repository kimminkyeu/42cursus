#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {

private:
	Brain* 		_brain;

public:
	Cat();
	Cat& operator= (const Cat& animal);
	Cat(const Cat& animal);
	Cat(const std::string& idea);

	virtual ~Cat() /* override (C++11) */;
	virtual void makeSound() const /* override (C++11) */;

	void changeMemory(const std::string& memory);
};




#endif // Cat.hpp
