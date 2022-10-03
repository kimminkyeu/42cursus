#include "ShrubberyCreationForm.hpp"

const std::string ShrubberyCreationForm::treeAscii =
"                ,@@@@@@@,                 \n"
"       ,,,.   ,@@@@@@/8@@, .oo8888o.      \n"
"    ,&%%&%&&%,@@@@@/@@@@@@,888888/888    \n"
"   ,%&%&&%&&%,@@@@@@/@@@8888888/88888'    \n"
"   %&&%&%&/%&&%@@@@/ /@@@88888888888'    \n"
"   %&&%/ %&%%&&@@ V /@@' `888 `/88'     \n"
"    `&% ` /%&'    |.|         | |'       \n"
"       |o|        | |         | |         \n"
"       |.|        | |         | |         \n"
"    \\/ ._ //_/__/  \\_//__\\/. \\_//__/_ \n";

// for OCForm
ShrubberyCreationForm::ShrubberyCreationForm()
	:Form("Shrubbery Creation", _requiredGradeToSign, _requiredGradeToExecute), _target("NoTarget")
{
	std::cout << "ShrubberyCreationForm default constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &form)
	:Form(form), _target(form._target)
{
	std::cout << "ShrubberyCreationForm copy constructor called\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called\n";
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &form)
{
	// Form::operator=(form);
	dynamic_cast<Form&>(*this) = dynamic_cast<const Form&>(form);
	this->_target = form._target;
	return (*this);
}

// Here for subject
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
	:Form("Shrubbery Creation", _requiredGradeToSign, _requiredGradeToExecute), _target(target)
{
	std::cout << "ShrubberyCreationForm std::string target constructor called\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& name, const std::string &target)
	:Form(name, _requiredGradeToSign, _requiredGradeToExecute), _target(target)
{
	std::cout << "ShrubberyCreationForm std::string name+target constructor called\n";
}


std::string ShrubberyCreationForm::getTarget() const
{
	return (_target);
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false) {
		throw (Form::FormUnsignedExecutionException());
	} else if (this->getGradeToExecute() < bureaucrat.getGrade()) {
		throw (Form::GradeUnsatisfiedException(bureaucrat.getGrade(), getGradeToExecute()));
	} else {
		std::ofstream writeFile(_target, std::ios::out | std::ios::app);
		if (writeFile.is_open())
		{
			writeFile << this->treeAscii;
			writeFile.close();
		}
	}
}
