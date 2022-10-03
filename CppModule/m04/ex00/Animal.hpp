#pragma once
#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal {

protected:
	std::string _type;


public:
	Animal();

	virtual ~Animal();

	Animal(const Animal& animal);
	Animal& operator= (const Animal& animal);

	virtual void makeSound() const;  // Animal pointer를 써도 cat의 makeSound 호출하기.

	// WARN:  아래 함순는 다형성이 필요 없으므로 virtual을 붙이지 않는다.
	std::string getType() const;
};




#endif // Animal.hpp
