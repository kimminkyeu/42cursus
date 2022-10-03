#include "Harl.hpp"

void	Harl::_debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n";
}

void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n";
}

void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years where as you started working here since last month.\n";
}

void	Harl::_error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now.\n";
}

void Harl::complain(std::string level)
{
  static const std::string cmdLine[] = {"DEBUG", "INFO", "WARNING", "ERROR"}; // NOTE:  why use static?
  // this->callBackFuncs = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};  FIX:  왜 안되지?
  this->callBackFuncs[0] = &Harl::_debug;
  this->callBackFuncs[1] = &Harl::_info;
  this->callBackFuncs[2] = &Harl::_warning;
  this->callBackFuncs[3] = &Harl::_error;

  int state = 0;
  for (; state < cmdLine->length(); state++) {
    if (cmdLine[state] == level) {
      (this->*callBackFuncs[state])(); // FIX:  이건 무엇인고...
      return;
    }
  };
  std::cout << "Command doesn't exist\n";
}
