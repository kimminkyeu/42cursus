#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

namespace HarlState {
	enum E_LEVEL {
		E_DEBUG,
		E_INFO,
		E_WARNING,
		E_ERROR,
	};
};

class Harl {

private:
	void	_debug( void ) const;
	void	_info( void ) const;
	void	_warning( void ) const;
	void	_error( void ) const;

public:
	Harl(std::string level);

	void	complain( std::string level );

};

#endif // HARL_HPP
