/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 21:17:26 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/23 21:17:28 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie*	z1 = newZombie("Foo");
	z1->announce();

	randomChump("Bar1");
	randomChump("Bar2");

	delete z1;
	return (0);
}
