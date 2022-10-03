#pragma once
#ifndef SPAN_HPP
# define SPAN_HPP

#include <cstddef> //size_t
#include <iostream>
// #include <cstdlib>
// #include <algorithm>
#include <vector>
#include <string>

class Span
{
private:
	std::vector<int> _vec;
	int	_maximumInts;

public:
	Span();
	~Span();
	Span(const int& nmemb);
	Span(const Span& span);
	Span& operator= (const Span& span);

	// push_back
	void addNumber(const int& integer);
	int	shortestSpan();
	int longestSpan();
	int operator[](const int& index) const;

	int size() const;
	void fillSpanRandom();
};

std::ostream& operator<< (std::ostream& out, const Span& span);

#endif // Span.hpp
