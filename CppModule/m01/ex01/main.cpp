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
	const int NUM = 5;

	Zombie* hordes = zombieHorde(NUM, "jake");

	for (int i=0; i < NUM; i++)
	{
		hordes[i].announce();
	}
	delete[] hordes;
	return (0);
}
