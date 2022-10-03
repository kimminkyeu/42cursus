#include <random>
#include <iostream>
#include "Class.hpp"

/**
 *? NOTE:  What is dynamic_cast ?
 * ---------------------------------------------------------------
 ** dynamic_cast is an operator that converts data from one type to another type.
 ** In C++, dynamic casting is mainly used for [safe downcasting] at run time.
 * https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/
 * (1) check if pointer(or reference) can be down_casted(Parent* => Child*) in run-time.
 * (2) if ok, then returns it's down_casted pointer. (child*)
 *! (3) Pointer*    : if not ok, then returns null pointer.
 *! (4) reference&  : if not ok, then bad_cast exception occurs.

	--> But why reference is exception?
	--> when it fails for a reference type it can't return a null reference,
	    so an exception is the only reasonable way to signal a problem.
 */

Base* generate(void)
{
	std::random_device rd; // make random device
	std::mt19937 gen(rd()); // 난수 생성 엔진 초기화
	std::uniform_int_distribution<int> dis(0, 2); // 0부터 6까지 균일분포 적용
	int val = dis(gen);

	switch (val)
	{
	case 0:
		std::cout << "generating A*\n";
		return (new A());
	case 1:
		std::cout << "generating B*\n";
		return (new B());
	case 2:
		std::cout << "generating C*\n";
		return (new C());
	default:
		return (NULL);
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "type: " << "A*\n";
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "type: " << "B*\n";
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "type: " << "C*\n";
	else
		std::cout << "type: unknown derived type\n";
}

void identify(Base& p)
{
	bool isA = true;
	bool isB = true;
	bool isC = true;

	try { (void)dynamic_cast<A&>(p); } catch (std::bad_cast& e){ isA = false; }
	try { (void)dynamic_cast<B&>(p); } catch (std::bad_cast& e){ isB = false; }
	try { (void)dynamic_cast<C&>(p); } catch (std::bad_cast& e){ isC = false; }

	if (isA == true)
		std::cout << "type: " << "A&\n";
	else if (isB == true)
		std::cout << "type: " << "B&\n";
	else if (isC == true)
		std::cout << "type: " << "C&\n";
	else
		std::cout << "type: unknown derived type\n";
}

int main(void)
{
	Base* ptr = NULL;

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	std::cout << "\n";

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	std::cout << "\n";

	ptr = generate();
	identify(ptr);
	identify(*ptr);
	delete ptr;

	return (0);
}
