#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "Contact.hpp"

/*  WARNING: The Orthodox Canonical Class Form
 * (1) A default constructor: used internally to initialize objects and data members when no other value is available.
 * (2) A copy constructor: used in the implementation of call-by-value parameters.
 * (3) An assignment operator: used to assign one value to another.
 * (4) A destructor: Invoked when an object is deleted. 
 */

class PhoneBook {
	private:
		Contact contacts[8];
		size_t	size; // number of data in contacts.

		// NOTE: Helper function
		const std::string	setWidth(std::string _str) const;

	public:
		// NOTE: Contstructor / Destructor.
		PhoneBook(); // default constructor
		PhoneBook(const PhoneBook& _phonebook); // copy constructor (Deep copy)
		~PhoneBook(); // default destructor
		
		// NOTE: member functions.
		size_t				getSize() const;
		const Contact*		search(const int& index) const;
		void				add(const Contact& _contact);
		void				print(const int& _width = 10) const; // default parameter in *.hpp
		
		// NOTE: Operator Overloading.
		Contact&			operator[] (const int& _index);
		PhoneBook&			operator= (const PhoneBook& _phonebook);
};

#endif /* PHONEBOOK_HPP */
