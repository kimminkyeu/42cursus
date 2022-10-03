
/**
 * NOTE:  Stack unwinding.
 * 	: throw한 data를 받는 곳(catch)까지 stack을 되감는 현상.
 *  : return을 계속해서 받아가며 예외처리를 하는 곳까지 전달.
 */

#include <exception>
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	// WARN:  Exception throw from Form class need to be caught in main()!
	Bureaucrat jack("jack", 2);
	try
	{
		ShrubberyCreationForm("Home").beExecuted(jack);
	}
	catch (Form::Exception& e)
	{
		std::cout << jack << " can't execute form because " << e.what() << "\n";
	}
	std::cout << "\n";

	Bureaucrat peter("peter", 29);
	try
	{
		ShrubberyCreationForm("Home").beSigned(peter).beExecuted(jack);
	}
	catch (Form::Exception& e)
	{
		std::cout << jack << " can't execute form because " << e.what() << "\n";
	}
	std::cout << "\n";


	RobotomyRequestForm weapon1("Killer Robot - 1");
	Bureaucrat("Paul", 5).signForm(weapon1).executeForm(weapon1);
	std::cout << "\n";

	RobotomyRequestForm weapon4("Killer Robot - 4");
	Bureaucrat("Paul", 5).signForm(weapon1).executeForm(weapon1);
	std::cout << "\n";

	RobotomyRequestForm weapon2("Killer Robot - 2");
	Bureaucrat("Ellie", 5).signForm(weapon2).executeForm(weapon2);
	std::cout << "\n";


	PresidentialPardonForm pardon("Jack the Ripper");
	Bureaucrat("Biden", 1).signForm(pardon).executeForm(pardon);
	std::cout << "\n";


	return (0);
}
