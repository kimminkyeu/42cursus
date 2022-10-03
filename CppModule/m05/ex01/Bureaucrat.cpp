#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat()
	: _name("No_name"), _grade(150)
{
	std::cout << "Bureaucrat default constructor called\n";
}

// i am inside Bureaucrat class. this is in class level.
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat)
	: _name(bureaucrat._name), _grade(bureaucrat._grade)
{
	std::cout << "Bureaucrat copy constructor called\n";
}
Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called\n";
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
	this->_grade = bureaucrat._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const std::string& name, const unsigned int &grade)
	:_name(name), _grade(grade)
{
	std::cout << "Bureaucrat " << _name << " with grade " << _grade << " constructor called\n";
	if (grade > 150) {
		throw (Bureaucrat::GradeTooLowException());
	} else if (grade < 1) {
		throw (Bureaucrat::GradeTooHighException());
	} else {
		this->_grade = grade;
	}
}

std::string Bureaucrat::getName() const
{
	return (this->_name);
}
unsigned int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::increaseGrade()
{
	if (this->_grade <= 1) {
		throw (Bureaucrat::GradeTooHighException());
	} else {
		this->_grade--;
	}
}
void Bureaucrat::decreaseGrade()
{
	if (this->_grade >= 150) {
		throw (Bureaucrat::GradeTooLowException());
	} else {
		this->_grade++;
	}
}

std::ostream& operator<< (std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << "<Bureaucrat " << bureaucrat.getName() << ", grade:" << bureaucrat.getGrade() << ">";
	return (out);
}

const char* Bureaucrat::Exception::what() const throw()
{
	return ("[Exception: default]");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("[Exception: Grade <= 1]");
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("[Exception: Grade >= 150]");
}

// NOTE:  ex01
void Bureaucrat::signForm(Form& form)
{
	try
	{
		form.beSigned(*this);
	}
	catch (Form::Exception &e) // WARN:  every exception's will be caught here...
	{
		std::cout << *this << " can't sign form because " << e.what() << "\n";
	}
	/**
	 * ? To handle each exception case....
	catch (Form::GradeUnsatisfiedException& e)
	{
		...
	}
	catch (Form::FormAlreadySignedException& e)
	{
		...
	}
	catch (...)  --> 위에서 안걸린 모든 exception은 여기로.
	{
		...
	}

	*/
}
