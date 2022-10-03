#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	:Form("NoName", _requiredGradeToSign, _requiredGradeToExecute), _target("NoTarget")
{
	std::cout << "RobotomyRequestForm default constructor called\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &form)
	:Form(form), _target(form._target)
{
	std::cout << "RobotomyRequestForm copy constructor called\n";
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called\n";
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &form)
{
	// Form::operator=(form);
	dynamic_cast<Form&>(*this) = dynamic_cast<const Form&>(form);
	this->_target = form._target;
	return (*this);
}

// Here for subject
RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
	:Form("NoName", _requiredGradeToSign, _requiredGradeToExecute), _target(target)
{
	std::cout << "RobotomyRequestForm std::string target constructor called\n";
}

std::string RobotomyRequestForm::getTarget() const
{
	return (_target);
}

void RobotomyRequestForm::beExecuted(const Bureaucrat &bureaucrat) const
{
	if (this->getIsSigned() == false) {
		throw (Form::FormUnsignedExecutionException());
	} else if (this->getGradeToExecute() < bureaucrat.getGrade()) {
		throw (Form::GradeUnsatisfiedException(bureaucrat.getGrade(), getGradeToExecute()));
	} else {
		std::cout << "Ggggg... Drilling Noise....\n";

		std::random_device rd; // make random device
		std::mt19937 gen(rd()); // 난수 생성 엔진 초기화
		std::uniform_int_distribution<int> dis(0, 5); // 0부터 6까지 균일분포 적용
		if (dis(gen) < 3) /* 50% */ {
			std::cout << this->getTarget() << " has become a robot.\n";
		} else {
			throw(RobotomyRequestForm::FailureException());
		}
	}
}

const char* RobotomyRequestForm::FailureException::what() const throw()
{
	return ("[Robotomy Failure Exception]");
}
