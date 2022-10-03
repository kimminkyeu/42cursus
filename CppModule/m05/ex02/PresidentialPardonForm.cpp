#include "PresidentialPardonForm.hpp"

// for OCForm
PresidentialPardonForm::PresidentialPardonForm()
	:Form("NoName", _requiredGradeToSign, _requiredGradeToExecute), _target("NoTarget")
{
	std::cout << "PresidentialPardonForm default constructor called\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &form)
	:Form(form), _target(form._target)
{
	std::cout << "PresidentialPardonForm copy constructor called\n";
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called\n";
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &form)
{
	// Form::operator=(form);
	dynamic_cast<Form&>(*this) = dynamic_cast<const Form&>(form);
	this->_target = form._target;
	return (*this);
}

// Here for subject
PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
	:Form("NoName", _requiredGradeToSign, _requiredGradeToExecute), _target(target)
{
	std::cout << "PresidentialPardonForm std::string target constructor called\n";
}

std::string PresidentialPardonForm::getTarget() const
{
	return (_target);
}

void PresidentialPardonForm::beExecuted(const Bureaucrat &bureaucrat) const /*override*/
{
	if (this->getIsSigned() == false) {
		throw (Form::FormUnsignedExecutionException());
	} else if (this->getGradeToExecute() < bureaucrat.getGrade()) {
		throw (Form::GradeUnsatisfiedException(bureaucrat.getGrade(), getGradeToExecute()));
	} else {
		std::cout << this->_target << " was pardonned by Zafod Beeblebrox\n";
	}
}
