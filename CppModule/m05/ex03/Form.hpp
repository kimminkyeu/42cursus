#pragma once
#ifndef FORM_HPP
# define FORM_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form {

private:
	const std::string _name;
	bool _isSigned;
	const unsigned int _grade_to_sign;
	const unsigned int _grade_to_execute;

public:
	Form();
	virtual ~Form();
	Form(const Form& form);
	Form& operator= (const Form& form);

	Form(const std::string& name, const unsigned int& grade_to_sign, const unsigned int& grade_to_execute);

	std::string getName() const;
	unsigned int getGradeToSign() const;
	unsigned int getGradeToExecute() const;
	bool getIsSigned() const;

	// NOTE:  Ex01
	Form& beSigned(const Bureaucrat& b);

	// NOTE:  Ex02 ----------------------------------------------------
	virtual void beExecuted(const Bureaucrat& b) const /* override */;
	// ----------------------------------------------------------------

	class Exception : public std::exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	// if grade_to_sign / execute is out-of-range
	class GradeTooLowException : public Form::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	// if grade_to_sign / execute is out-of-range
	class GradeTooHighException : public Form::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	// NOTE:  if Bureaucrat's grade is lower than grade_to_sign
	class GradeUnsatisfiedException : public Form::Exception {
	private:
		std::string _customMessage;
	public:
		GradeUnsatisfiedException(const unsigned int& bureaucratGrade, const unsigned int& formGrade);
		virtual ~GradeUnsatisfiedException() throw();
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	class FormAlreadySignedException : public Form::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	class FormUnsignedExecutionException : public Form::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};
};

std::ostream& operator<< (std::ostream& out, const Form& form);

#endif // Form.hpp
