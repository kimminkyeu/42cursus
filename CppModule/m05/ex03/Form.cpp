#include "Form.hpp"
#include <string>

Form::Form()
	: _name("No_name"), _grade_to_sign(150), _grade_to_execute(150), _isSigned(false)
{
	std::cout << "Form default constructor called\n";
}

// i am inside Form class. this is in class level.
Form::Form(const Form &form)
	: _name(form._name), _grade_to_sign(form._grade_to_sign), _grade_to_execute(form._grade_to_execute), _isSigned(form._isSigned)
{
	std::cout << "Form copy constructor called\n";
}

Form::~Form()
{
	std::cout << "Form destructor called\n";
}

Form& Form::operator=(const Form &form)
{
	this->_isSigned = form._isSigned;
	return (*this);
}

Form::Form(const std::string& name, const unsigned int& grade_to_sign, const unsigned int& grade_to_execute)
	:_name(name), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute), _isSigned(false)
{
	if (grade_to_sign > 150 || grade_to_execute > 150) {
		throw (Form::GradeTooLowException());
	} else if (grade_to_sign < 1 || grade_to_execute < 1) {
		throw (Form::GradeTooHighException());
	} else {
		std::cout << *this << " constructor called\n";
	}
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

std::string Form::getName() const
{
	return (this->_name);
}
unsigned int Form::getGradeToSign() const
{
	return (this->_grade_to_sign);
}

unsigned int Form::getGradeToExecute() const
{
	return (this->_grade_to_execute);
}

std::ostream& operator<< (std::ostream& out, const Form& form)
{
	out << "<";
	out << form.getName();
	out << ", gradeToSign:" << form.getGradeToSign();
	out << ", gradeToExecute:" << form.getGradeToExecute();
	out << ", isSigned:" << form.getIsSigned();
	out << ">";
	return (out);
}

Form& Form::beSigned(const Bureaucrat &b) // 만약 여기에 throw()함수를 적으면 어케 될까?
{
	if (_isSigned == true) {
		throw (Form::FormAlreadySignedException());
	} else if (b.getGrade() > _grade_to_sign) {
		throw (Form::GradeUnsatisfiedException(b.getGrade(), _grade_to_sign));
	} else {
		_isSigned = true;
		std::cout << b << " signed " << *this << std::endl;
	}
	return (*this); // chaining.
}

void Form::beExecuted(const Bureaucrat &b) const
{
	if (_isSigned == false) {
		throw (Form::FormUnsignedExecutionException());
	} else if (b.getGrade() > _grade_to_execute) {
		throw (Form::GradeUnsatisfiedException(b.getGrade(), _grade_to_sign));
	} else {
		std::cout << b << " executed " << *this << std::endl;
	}
}

const char* Form::Exception::what() const throw()
{
	return ("[Exception: default]");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("[Exception: Grade <= 1]");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("[Exception: Grade >= 150]");
}

Form::GradeUnsatisfiedException::GradeUnsatisfiedException(const unsigned int& bureaucratGrade, const unsigned int& formGrade)
	:_customMessage("[Exception: bureaucrat's grade is " + std::to_string(bureaucratGrade) + ", which is lower than " + std::to_string(formGrade) + "]")
{}

Form::GradeUnsatisfiedException::~GradeUnsatisfiedException() throw()
{}

const char* Form::GradeUnsatisfiedException::what() const throw()
{
	return (_customMessage.c_str());
}

const char* Form::FormAlreadySignedException::what() const throw()
{
	return ("[Exception: Form has been already signed]");
}

const char* Form::FormUnsignedExecutionException::what() const throw()
{
	return ("[Exception: Execution on unsigned form]");
}
