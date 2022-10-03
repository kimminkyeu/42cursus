#include <iostream>
#include "Iter.hpp"

class Awesome
{
public:
	Awesome(void) : _n(42) { return; }
	int get(void) const { return this->_n; }

private:
	int _n;
};

std::ostream& operator<<(std::ostream& out, const Awesome& ref)
{
	out << ref.get();
	return (out);
}

template <typename T>
void print(T& x)
{
	std::cout << x << std::endl;
	return;
}

// int main()
// {
// 	return 0;
// }

int main(void)
{
	int arrInt[5] = {2, 3, 4, 5, 6};
	iter<int>(arrInt, 5, increment<int>);
	for (size_t i=0; i<5; i++) {
		std::cout << arrInt[i] << " ";
	}
	std::cout << "\n";




	char arrChar[5] = {'a', 'b', 'c', 'd', 'f'};
	iter<char>(arrChar, 5, increment<char>);
	for (size_t i=0; i<5; i++) {
		std::cout << arrChar[i] << " ";
	}
	std::cout << "\n";



	int tab[] = {0, 1, 2, 3, 4}; // );
	iter<int>(tab, 5, print<int>);
	Awesome tab2[5] = {Awesome()};
	iter<Awesome>(tab2, 5, print<Awesome>);




	return (0);
}
