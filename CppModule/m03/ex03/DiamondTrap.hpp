#pragma once
#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

//  NOTE:  Solution to Diamond Inheritance
// https://www.makeuseof.com/what-is-diamond-problem-in-cpp/

/** WARN:     *
 * Here we have used the virtual keyword when classes Father and Mother inherit the Person class.
 * This is usually called “virtual inheritance,"
 * which guarantees that only a single instance of the inherited class (in this case, the Person class) is passed on.
 * In other words, the Child class will have a single instance of the Person class, shared by both the Father and Mother classes.
 * By having a single instance of the Person class, the ambiguity is resolved.
 * */

// in ScavTrap.hpp, you can see [ class ScavTrap : virtual public ClapTrap ]
// in FragTrap.hpp, you can see [ class FragTrap : virtual public ClapTrap ]

// FIX:   Virtual Table을 이용하기 때문에 Ambiguity 문제가 해결되는 걸까?

// WARN:  아래 public을 작성한 순서에 따라 생성자 소멸자 호출 순서가 달라진다.
class DiamondTrap : public ScavTrap, public FragTrap {

private:
	std::string _name;

public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(const DiamondTrap& trap);
	DiamondTrap(const std::string& name);
	DiamondTrap& operator= (const DiamondTrap& trap);

	// NOTE:  using declaration: 만약 같은 attack() 함수들이 존재한다면, ScavTrap에 있는 걸 써라.
	using	ScavTrap::attack;

	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);

	void whoAmI() const;
	// NOTE:  -Wshadow / -Wno-shadow compiler flag

/* 	[-Wshadow]
	: 지역변수가 다른 지역변수, 매개변수 등(shadow) 덮는 경우 Warning이 발생합니다
	[-Wno-shadow]
	: Do not warn whenever a local variable shadows an instance variable in an Objective-C method.
*/

};


#endif // DiamondTrap.hpp
