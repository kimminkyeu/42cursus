
/**
 * NOTE:  Stack unwinding.
 * 	: throw한 data를 받는 곳(catch)까지 stack을 되감는 현상.
 *  : return을 계속해서 받아가며 예외처리를 하는 곳까지 전달.
 */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <exception>

int main(void)
{
	Form topSecret("CIA TopSecret", 3, 3);
	std::cout << "\n";
	{
		Bureaucrat jack("Jack", 45);
		jack.signForm(topSecret);
	}
	{
		std::cout << "\n";
		Bureaucrat paul("Mr.President", 1);
		paul.signForm(topSecret);
		std::cout << "\n";

		// if Hacker tries to sign top-secret... (이미 서명 완료된)
		std::cout << "\n";
		Bureaucrat("Hacker-01", 3).signForm(topSecret);
		std::cout << "\n";
	}
	return (0);
}
