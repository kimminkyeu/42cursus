#pragma once
#include <ostream>
#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
	const std::string _name;
	unsigned int _grade;

public:
	Bureaucrat();
	Bureaucrat(const Bureaucrat& bureaucrat);
	~Bureaucrat();
	Bureaucrat& operator= (const Bureaucrat &bureaucrat);

	Bureaucrat(const std::string& name, const unsigned int& grade);

	std::string getName() const;
	unsigned int getGrade() const;

	void increaseGrade();
	void decreaseGrade();

/**

	*  NOTE:   (0) Why try-catch exception style ?
	-------------------------------------------------------------------
	*?	1. (Good) C언어에서 exit 안쓰고 함수마다 int 타입으로 return값 계속 이어받아서 main문까지 전달해서 에러처리 했던 기억 나는가?
	         => 그걸 편하게 해주는게 std::exception 라이브러리다.
	*!	2. (Bad) 그러나 c스타일 if/else 예외처리보다 느리다. 따라서 Performance 보다 안정성(Safety)가 중요한 서버, 네트워크에서 주로 사용된다.
가

	*  NOTE:   (1) std::exception Class's virtual ?
	-------------------------------------------------------------------
   	   _NODISCARD virtual char const* what() const
       {
          return _Data._What ? _Data._What : "Unknown exception";
       }
	   => Override 해서 쓰라고 되있음.

	*  NOTE:   (2) What is throw() ? (Deprecated in C++11, will be removed in C++20)
	-------------------------------------------------------------------
	*!   C++98 [ void MyFunction(int i) throw(); ]
		tells the compiler that the function does not throw any exceptions. (컴파일러가 Performance 최적화할 때 큰 역할을 한다)
		However, in /std:c++14 mode this could lead to undefined behavior if the function does throw an exception.
		Therefore we recommend using the noexcept operator instead of the one above:

	*?   C++14 [ void MyFunction(int i) noexcept; ]
		noexcept가 붙은 함수에서 exception이 발생할 경우, 내부에서 std::terminate이 실행된다.

*/

	class Exception : public std::exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	class GradeTooLowException : public Bureaucrat::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};

	class GradeTooHighException : public Bureaucrat::Exception {
	public:
		virtual const char* what() const throw() /* override noexcept */ ;
	};
};

std::ostream& operator<< (std::ostream& out, const Bureaucrat& bureaucrat);


#endif // BUREAUCRAT_HPP
