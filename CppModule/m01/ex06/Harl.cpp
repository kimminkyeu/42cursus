#include "Harl.hpp"

void	Harl::_debug(void) const
{
	std::cout << "[ DEBUG ]\n";
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n\n";
}

void	Harl::_info(void) const
{
	std::cout << "[ INFO ]\n";
	std::cout << "I cannot believe adding extra bacon costs more money.\nYou didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n\n";
}

void	Harl::_warning(void) const
{
	std::cout << "[ WARNING ]\n";
	std::cout << "I think I deserve to have some extra bacon for free.\nI’ve been coming for years where as you started working here since last month.\n\n";
}

void	Harl::_error(void) const
{
	std::cout << "[ ERROR ]\n";
	std::cout << "This is unacceptable, I want to speak to the manager now.\n\n";
}

void Harl::complain(std::string level)
{
  static const std::string cmdLine[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int state = 0;
  for (; state < cmdLine->length(); state++) {
	if (cmdLine[state] == level) {
		break;
	}
  };

/**
 *!  WARN:  Use Enum Type or (0 to N) numbers for {Compiler's Switch case optimization}
			1. https://modoocode.com/16  --> [KEYWORD = jump-table] */

/**
 *!  WARN:   Commenting "fall through" in switch is very important. (Debugging + Mistake handling)
			1. https://lwn.net/Articles/794944/
			2. https://stackoverflow.com/questions/45129741/gcc-7-wimplicit-fallthrough-warnings-and-portable-way-to-clear-them
			3. https://docs.popekim.com/ko/coding-standards/cpp */

  switch (state) {
	case HarlState::E_DEBUG: 	// 0
		this->_debug();
		/* fall through */
	case HarlState::E_INFO: 	// 1
		this->_info();
		/* fall through */
	case HarlState::E_WARNING:	// 2
		this->_warning();
		/* fall through */
	case HarlState::E_ERROR:	// 3
		this->_error();
		break;
	default:
		std::cout << "[ Probably complaining about insignificant problems ]\n";
		break;
  }
}

// NOTE:  Constructor call complain() function
Harl::Harl(std::string level)
{
	this->complain(level);
}
