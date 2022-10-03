#pragma once
#ifndef INTERN_HPP
# define INTERN_HPP

// #include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

namespace FormSpec {
	enum {
		E_DEFAULT_FORM, // 0
		E_SHRUBBERY_CREATION_FORM, // 1
		E_ROBOTOMY_REQUEST_FORM, // 2
		E_PRESIDENTIAL_PARDON_FORM, // 3
	};
};

class Intern {
private:
	static const std::string _Spec[4];
	static const int _getSpecIndex(const std::string& formName);

public:
	Intern();
	~Intern(); // no need to use virtual.
	Intern(const Intern& intern);
	Intern& operator= (const Intern& intern);

	Form* makeForm(const std::string& formName, const std::string& formTarget);

	class UnkownFormException : public Form::Exception {
	public:
		const char* what() const throw();
	};
};

#endif // Intern.hpp
