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

#include <string>
#include <iostream>

int main(void)
{
	std::string 	s1 = "HI THIS IS BRAIN";
	std::string*	stringPTR = &s1;
	std::string&	stringREF = s1;

	std::cout << "stringVar addr: " << &s1 << std::endl;
	std::cout << "stringPTR addr: " << stringPTR << std::endl;
	std::cout << "stringREF addr: " << &stringREF << std::endl;


	std::cout << std::endl;
	std::cout << "stringVar val: " << s1 << std::endl;
	std::cout << "stringPTR val: " << *stringPTR << std::endl;
	std::cout << "stringREF val: " << stringREF << std::endl;



	return (0);
}
