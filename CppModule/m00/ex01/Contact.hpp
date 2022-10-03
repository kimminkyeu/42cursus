#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>
#include <iostream>
#include <iomanip>

/*  NOTE: The Orthodox Canonical Class Form
 * (1) A default constructor: used internally to initialize objects and data members when no other value is available.
 * (2) A copy constructor: used in the implementation of call-by-value parameters.
 * (3) An assignment operator: used to assign one value to another.
 * (4) A destructor: Invoked when an object is deleted. */

class Contact {

	private:
		std::string firstName;
		std::string lastName;
		std::string nickName;
		std::string phoneNumber;
		std::string darkestSecret;

	public:

		// NOTE: Contstructor / Destructor
		Contact();
		Contact(const Contact& _contact);
		Contact(const std::string& _firstName, const std::string& _lastName, const std::string& _nickName, const std::string& _phoneNumber, const std::string& _darkestSecret);
		~Contact();

		// NOTE: Operator Overloading
		Contact& operator= (const Contact& _contact);

		// NOTE: Getter
		const std::string getFirstName() const;
		const std::string getLastName() const;
		const std::string getNickName() const;
		const std::string getPhoneNumber() const;
		const std::string getDarkestSecret() const;

		// NOTE: Setter
		void		setAll(const std::string& _firstName, const std::string& _lastName, const std::string& _nickName, const std::string& _phoneNumber, const std::string& _darkestSecret);
		void		setFirstName(const std::string& _firstName);
		void		setLastName(const std::string& _lastName);
		void		setNickName(const std::string& _nickName);
		void		setPhoneNumber(const std::string& _phoneNumber);
		void		setDarkestSecret(const std::string& _darkestSecret);
};

// NOTE: Overloading to Ostream class, not out Contact class.
std::ostream& operator<<(std::ostream& out, const Contact& _contact);

#endif /* CONTACT_HPP */
