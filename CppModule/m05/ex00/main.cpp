/**
 * NOTE:  Stack unwinding.
 * 	: throw한 data를 받는 곳(catch)까지 stack을 되감는 현상.
 *  : return을 계속해서 받아가며 예외처리를 하는 곳까지 전달.
 */

#include "Bureaucrat.hpp"
#include <exception>

int main(void)
{
	// NOTE:  Without Try, Catch. --> works like assert()
	/*{
          Bureaucrat t1("Jake", 3);
          t1.increaseGrade();
          t1.increaseGrade();
          t1.increaseGrade();

          Bureaucrat t2("Paul", 149);
          t2.decreaseGrade();
          t2.decreaseGrade();
          t2.decreaseGrade();
    }*/

	// NOTE:  With Try, Catch.
	{
        Bureaucrat t1("Jake", 3);
		try
		{
			t1.increaseGrade();
			std::cout << t1 << std::endl;
        	t1.increaseGrade();
			std::cout << t1 << std::endl;
        	t1.increaseGrade();
			std::cout << t1 << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...) // every other exceptions
		{
			std::cout << "every other exceptions\n" << std::endl;
		}
    }
	std::cout << std::endl;
	{
        Bureaucrat t1("Paul", 149);
		try
		{
			t1.decreaseGrade();
			std::cout << t1 << std::endl;
			t1.decreaseGrade();
			std::cout << t1 << std::endl;
			t1.decreaseGrade();
			std::cout << t1 << std::endl;
		}
		catch (std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
		catch (...) // every other exceptions
		{
			std::cout << "every other exceptions\n" << std::endl;
		}
    }

	return (0);
}
