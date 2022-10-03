#pragma once
#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

public:
	std::string ideas[100];

	Brain();
	~Brain();
	Brain(const Brain& brain);
	// Brain(const Brain* brain_ptr);
	// Brain* operator= (const Brain* brain);
	Brain& operator= (const Brain& brain);
};

#endif // Brain.hpp
