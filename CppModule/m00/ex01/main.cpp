/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minkyeki <minkyeki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 20:52:01 by minkyeki          #+#    #+#             */
/*   Updated: 2022/08/23 21:14:04 by minkyeki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// for cin cout
#include <iomanip>	// for printing
#include <string>	// for std::string
#include <cstdlib>	// for atoi()
#include <cctype>	// for isdigit()

#include "Contact.hpp"
#include "PhoneBook.hpp"

namespace Color {
	const char *DEF_COLOR	= "\033[0;39m";
	const char *GRAY		= "\033[0;90m";
	const char *RED			= "\033[0;91m";
	const char *GREEN		= "\033[0;92m";
	const char *YELLOW		= "\033[0;93m";
	const char *BLUE		= "\033[0;94m";
	const char *MAGENTA		= "\033[0;95m";
	const char *CYAN		= "\033[0;96m";
	const char *WHITE		= "\033[0;97m";
}

void readlinePrompt(std::string messege, std::string &buf)
{
	std::cout << messege;
	while(std::getline(std::cin, buf) && buf.empty())
	{
		std::cout << "No input. Please type again.\n";
		std::cout << messege;
	}
}

Contact getContactFromKeyboard(std::string& buf)
{
	Contact tmpContact;

	readlinePrompt("First Name: ", buf);
	tmpContact.setFirstName(buf);
	readlinePrompt("Last Name: ", buf);
	tmpContact.setLastName(buf);
	readlinePrompt("Nick Name: ", buf);
	tmpContact.setNickName(buf);
	readlinePrompt("Phone Number: ", buf);
	tmpContact.setPhoneNumber(buf);
	readlinePrompt("Darkest Secret: ", buf);
	tmpContact.setDarkestSecret(buf);

	return (tmpContact);
}

int main()
{	
	std::string	buf;
	PhoneBook	myPhoneBook;

	while (true)
	{
		readlinePrompt("Enter CMD(ADD/SEARCH/EXIT): ", buf);
		if (buf == "ADD")
		{
			myPhoneBook.add(getContactFromKeyboard(buf));
			std::cout << Color::GREEN << "\t# Data successfully added!\n" << Color::DEF_COLOR << std::endl;
		} 
		else if (buf == "SEARCH") 
		{
			if (myPhoneBook.getSize() == 0)
			{
				std::cout << Color::RED << "\t# PhoneBook is empty\n" << Color::DEF_COLOR << std::endl;
			} 
			else 
			{
				myPhoneBook.print(10); // if no parameter, then 10 is default.
				int index;
				while (true)
				{
					readlinePrompt("Enter index: ", buf);
					index = std::atoi(buf.c_str());
					if (buf.size() == 1 && std::isdigit(buf.c_str()[0]) && index < static_cast<int>(myPhoneBook.getSize()))
					{
						std::cout << myPhoneBook[index] << std::endl;
						break ;
					}
					else
						std::cout << Color::RED << "\t# Please Enter Valid Index (Only number)\n" << Color::DEF_COLOR << std::endl;
				}
			}
		} 
		else if (buf == "EXIT") 
		{
			std::cout << Color::RED << "\t# Closing Program...\n" << Color::DEF_COLOR << std::endl;
			break ;
		} 
		else 
		{
			std::cout << Color::RED << "\t# Please enter valid command.\n" << Color::DEF_COLOR << std::endl;
		}
	}
	return (0);
}
