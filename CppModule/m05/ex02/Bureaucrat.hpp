#pragma once
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>
#include "Form.hpp"

class Form;

class Bureaucrat {
private:
	const std::string _name;
	unsigned int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& bureaucrat);
	~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat &bureaucrat);

	Bureaucrat(const std::string& name, const unsigned int& grade);

	std::string getName() const;
	unsigned int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

	class Exception : public std::exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	class GradeTooLowException : public Bureaucrat::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	class GradeTooHighException : public Bureaucrat::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	// NOTE:  For ex01.
	Bureaucrat& signForm(Form& form);
	// NOTE:  For ex02..
	void executeForm(const Form& form);
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& bureaucrat);


#endif // BUREAUCRAT_HPP
