#pragma once
#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "fstream"
#include "Form.hpp"

class ShrubberyCreationForm : public Form
{
private:
	std::string _target;

	// for tree Ascii Art
	static const std::string treeAscii;
	// Settings
	static const int _requiredGradeToSign = 145;
	static const int _requiredGradeToExecute = 137;

public:
	ShrubberyCreationForm();
	ShrubberyCreationForm(const ShrubberyCreationForm& form);
	virtual ~ShrubberyCreationForm();
	ShrubberyCreationForm& operator= (const ShrubberyCreationForm& form);

	ShrubberyCreationForm(const std::string& target);
	std::string getTarget() const;
	virtual void beExecuted(const Bureaucrat& bureaucrat) const;

};

#endif // ShrubberyCreationForm.hpp
