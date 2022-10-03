/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:17:37 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/23 21:17:38 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {

private:
	std::string _name;

public:

	Zombie(std::string name);
	~Zombie();

	void 	announce(void);

};

void	randomChump(std::string name);
Zombie*	newZombie(std::string name);

#endif /* ZOMBIE_HPP */
