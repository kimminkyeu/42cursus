
/**
 * NOTE:  Stack unwinding.
 * 	: throw한 data를 받는 곳(catch)까지 stack을 되감는 현상.
 *  : return을 계속해서 받아가며 예외처리를 하는 곳까지 전달.
 */

#include <exception>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

void	SignAndExecute(Form* form, const Bureaucrat& b)
{
	if (form != NULL)
		b.signForm(*form).executeForm(*form);
}

int main(void)
{
	Intern someRandomIntern;

	Form* f1 = NULL;
	Form* f2 = NULL;
	Form* f3 = NULL;
	Form* f4 = NULL;

	try
	{
		f1 = someRandomIntern.makeForm("robotomy request", "Bender A");
		f2 = someRandomIntern.makeForm("shrubbery creation", "Bender B");
		f3 = someRandomIntern.makeForm("presidential pardon", "Bender C");
		f4 = someRandomIntern.makeForm("unkown form", "Bender D");
	}
	catch (Intern::UnkownFormException& e)
	{
		std::cout << e.what() << std::endl;
	}

	Bureaucrat president("Biden", 1);

	SignAndExecute(f1, president);
	SignAndExecute(f2, president);
	SignAndExecute(f3, president);
	SignAndExecute(f4, president);

	delete f1;
	delete f2;
	delete f3;
	delete f4;
	system("leaks ex03 > leaks_result_temp; cat leaks_result_temp | grep leaked && rm -rf leaks_result_temp");
	return (0);
}
