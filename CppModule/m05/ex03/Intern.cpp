#include "Intern.hpp"

const std::string Intern::_Spec[] = {
	"default",
	"robotomy request",
	"shrubbery creation",
	"presidential pardon",
};

Intern::Intern()
{
	std::cout << "Intern default constructor called\n";
}

Intern::~Intern()
{
	std::cout << "Intern default destructor called\n";
}

Intern::Intern(const Intern& intern)
{
	std::cout << "Intern copy constructor called\n";
}

Intern& Intern::operator= (const Intern& intern)
{
	return (*this);
}

const int Intern::_getSpecIndex(const std::string& formName)
{
	int	arr_len = sizeof(_Spec) / sizeof(*_Spec);

	for (int i=0; i < arr_len; i++) {
		if (_Spec[i] == formName) {
			return (i);
		}
	}
	return (-1);
}

Form* Intern::makeForm(const std::string& formName, const std::string& formTarget)
{
	Form *form_ptr;
	switch(_getSpecIndex(formName))
	{
	case FormSpec::E_DEFAULT_FORM:
		form_ptr = new Form();
		break;
	case FormSpec::E_SHRUBBERY_CREATION_FORM:
		form_ptr = new ShrubberyCreationForm(formTarget);
		break;
	case FormSpec::E_ROBOTOMY_REQUEST_FORM:
		form_ptr = new RobotomyRequestForm(formTarget);
		break;
	case FormSpec::E_PRESIDENTIAL_PARDON_FORM:
		form_ptr = new PresidentialPardonForm(formTarget);
		break;
	default: // if form not found
		throw(Intern::UnkownFormException());
		return (NULL);
		break;
	}
	std::cout << "Intern creates " << *form_ptr << "\n";
	return (form_ptr);
}

const char* Intern::UnkownFormException::what() const throw()
{
	return ("[Exception: Unknown form request]");
}
