#pragma once
#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "Form.hpp"

class PresidentialPardonForm : public Form
{
private:
	std::string _target;

	// for tree Ascii Art
	static const std::string treeAscii;
	// Settings
	static const int _requiredGradeToSign = 25;
	static const int _requiredGradeToExecute = 5;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(const PresidentialPardonForm& form);
	// WARN:  Use virtual!
	virtual ~PresidentialPardonForm();
	PresidentialPardonForm& operator= (const PresidentialPardonForm& form);

	PresidentialPardonForm(const std::string& name, const std::string& target);
	PresidentialPardonForm(const std::string& target);
	std::string getTarget() const;

	virtual void beExecuted(const Bureaucrat& bureaucrat) const /* override */;

};

#endif // PresidentialPardonForm.hpp
