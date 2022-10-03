#pragma once
#ifndef CAT_HPP
# define CAT_HPP

#include <string>
#include "Animal.hpp"

class Cat : public Animal {

public:
	Cat();
	Cat& operator= (const Cat& animal);
	Cat(const Cat& animal);

	virtual ~Cat() /* override (C++11) */;
	virtual void makeSound() const /* override (C++11) */;
};




#endif // Cat.hpp
