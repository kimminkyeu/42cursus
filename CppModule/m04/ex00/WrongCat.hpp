#pragma once
#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

public:
	WrongCat();
	WrongCat& operator= (const WrongCat& animal);
	WrongCat(const WrongCat& animal);

	~WrongCat() /* override (C++11) */;
	void makeSound() const /* override (C++11) */;

};

#endif // WrongCat.hpp
