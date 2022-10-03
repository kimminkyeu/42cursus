#pragma once
#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include <string>
#include <iostream>
#include "Brain.hpp"

class AAnimal {

protected:
	std::string _type;


public:
	AAnimal();

	// NOTE:  소멸자도 =0; 을 붙여야 하는가? --> no.
	// https://stackoverflow.com/questions/1219607/why-do-we-need-a-pure-virtual-destructor-in-c
	virtual ~AAnimal();
	/* The destructor is the only method that even if it is pure virtual has to have
	 an implementation in order to instantiate derived classes */

	AAnimal(const AAnimal& animal);
	AAnimal& operator= (const AAnimal& animal);
	std::string getType() const;

	// NOTE:  Pure virtual function with [virtual func() = 0;]
	virtual void makeSound() const = 0;  // NOTE:  = 0 -> 정의하지 않겠다.
	// --> 순수 가상 함수가 포함된 클래스는 순수추상클래스가 된다.
	// 따라서 AAnimal 클래스 인스턴스를 만들수 없고, 상속받아서 구현해야 한다.
	// 만약 0을 지우면, main문의 주석을 지워도 정상적으로 작동할 것이다.
};



#endif // AAnimal.hpp
