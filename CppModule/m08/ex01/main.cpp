#include <iostream>
#include "Span.hpp"

int main()
{
	std::cout << "\n[ Test 1 ]\n";

	Span sp = Span(5);

	try
	{
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;

		// NOTE:  Exception occurs
		sp.addNumber(19);
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n[ Test 2 ]\n";

	try
	{
		Span sp2(10);
		sp2.fillSpanRandom();
		std::cout << sp2 << std::endl;
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << '\n';
	}


	return 0;
}
