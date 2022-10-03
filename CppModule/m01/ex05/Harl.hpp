#pragma once
#ifndef HARL_HPP
# define HARL_HPP

#include <iostream>
#include <string>

class Harl {

private:
	void 	(Harl::*callBackFuncs[4])(void) const;

	void	_debug( void ) const;
	void	_info( void ) const;
	void	_warning( void ) const;
	void	_error( void ) const;

public:
	void	complain( std::string level );

};

#endif // HARL_HPP
