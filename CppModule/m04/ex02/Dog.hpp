#pragma once
#ifndef DOG_HPP
# define DOG_HPP

#include <string>
#include <cstring>
#include "Animal.hpp"

class Dog : public Animal {

private:
	Brain* 		_brain;

public:
	Dog();
	Dog(const std::string& idea);
	Dog(const Dog& animal);
	Dog& operator= (const Dog& animal);

	// 자식에서의 virtual은 "이거 virtual 받은거예요~ 라고 개발자에게 알려주기 위한 용도. "
	virtual ~Dog() /*override*/; // Override : ⚠️ keyword for Debugging, C++11
	virtual void makeSound() const /*override*/;  // Override : ⚠️ keyword for Debugging, C++11

	void	changeMemory(const std::string& idea);
};




#endif // Animal.hpp
