#include <vector>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);

	try
	{
		std::vector<int>::iterator iter = easyfind< std::vector<int> >(v, 2);
		std::cout << *iter << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}
