#pragma once
#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <random>
#include "Form.hpp"

class RobotomyRequestForm : public Form
{
private:
	std::string _target;
	// Settings
	static const int _requiredGradeToSign = 72;
	static const int _requiredGradeToExecute = 45;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(const RobotomyRequestForm& form);
	virtual ~RobotomyRequestForm();
	RobotomyRequestForm& operator= (const RobotomyRequestForm& form);

	RobotomyRequestForm(const std::string& target);
	std::string getTarget() const;

	virtual void beExecuted(const Bureaucrat& bureaucrat) const;

	class FailureException : public Form::Exception {
	public:
		virtual const char* what() const throw();
	};
};

#endif // RobotomyRequestForm.hpp
