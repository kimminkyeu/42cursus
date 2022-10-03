#include "Contact.hpp"

// NOTE: Contstructor

Contact::Contact(void)
{
	Contact::setAll("\0", "\0", "\0", "\0", "\0");
}

Contact::Contact(const Contact& _contact)
{
	*this = _contact;
}

Contact::Contact(const std::string& _firstName, const std::string& _lastName, const std::string& _nickName, const std::string& _phoneNumber, const std::string& _darkestSecret)
{
	Contact::setAll(_firstName, _lastName, _nickName, _phoneNumber, _darkestSecret);
};

Contact::~Contact(void){};

// NOTE: Getter

const std::string Contact::getFirstName() const
{
	return (this->firstName);
}

const std::string Contact::getLastName() const
{
	return (this->lastName);
}

const std::string Contact::getNickName() const
{
	return (this->nickName);
}

const std::string Contact::getPhoneNumber() const
{
	return (this->phoneNumber);
}

const std::string Contact::getDarkestSecret() const
{
	return (this->darkestSecret);
}

// NOTE: Setter

void Contact::setAll(const std::string& _firstName, const std::string& _lastName, const std::string& _nickName, const std::string& _phoneNumber, const std::string& _darkestSecret)
{
	this->firstName = _firstName;
	this->lastName = _lastName;
	this->nickName = _nickName;
	this->phoneNumber = _phoneNumber;
	this->darkestSecret = _darkestSecret;
}

void Contact::setFirstName(const std::string& _firstName)
{
	this->firstName = _firstName;
}

void Contact::setLastName(const std::string& _lastName)
{
	this->lastName = _lastName;
}

void Contact::setNickName(const std::string& _nickName)
{
	this->nickName = _nickName;
}

void Contact::setPhoneNumber(const std::string& _phoneNumber)
{
	this->phoneNumber = _phoneNumber;
}

void Contact::setDarkestSecret(const std::string& _darkestSecret)
{
	this->darkestSecret = _darkestSecret;
}

Contact& Contact::operator= (const Contact& _contact)
{
	this->setAll(_contact.getFirstName(), _contact.getLastName(), _contact.getNickName(), _contact.getPhoneNumber(), _contact.getDarkestSecret());
	return (*this);
}

std::ostream& operator<< (std::ostream& out, const Contact& _contact)
{
	out << "     First Name : " << _contact.getFirstName() << "\n";
	out << "      Last Name : " << _contact.getLastName() << "\n";
	out << "      Nick Name : " << _contact.getNickName() << "\n";
	out << "   Phone Number : " << _contact.getPhoneNumber() << "\n";
	out << " Darkest Secret : " << _contact.getDarkestSecret();
	return (out);
}
