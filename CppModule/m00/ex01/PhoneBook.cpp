#include <cstdlib>
#include <iomanip>

#include "Contact.hpp"
#include "PhoneBook.hpp"

// NOTE: Contstructor / Destructor
PhoneBook::PhoneBook(void) 
	: size(0) 
{};

PhoneBook::PhoneBook(const PhoneBook& _phonebook)
{
	*this = _phonebook;
}

PhoneBook::~PhoneBook(void){};

// NOTE: Getter
size_t PhoneBook::getSize() const
{
	return (this->size);
}

// NOTE: Member function 
void PhoneBook::add(const Contact& _contact)
{
	if (this->size == 8)
	{
		for (size_t i=0; i < this->size-1; i++)
		{
			this->contacts[i] = this->contacts[i+1];
		}
		this->contacts[this->size - 1] = _contact;
	} 
	else 
	{
		this->contacts[this->size] = _contact;
		this->size++;
	}
}

const Contact* PhoneBook::search(const int& _index) const
{
	if (_index < 0 || _index >= static_cast<int>(this->size))
	{
		return (NULL);
	} 
	else 
	{
		return (&this->contacts[_index]);
	}
}

void PhoneBook::print(const int& _width) const
{
	std::cout << "---------------------------------------------\n";
	std::cout << "|";
	std::cout << std::right << std::setw(_width) << "Index";
	std::cout << "|";
	std::cout << std::right << std::setw(_width) << "First Name";
	std::cout << "|";
	std::cout << std::right << std::setw(_width) << "Last Name";
	std::cout << "|";
	std::cout << std::right << std::setw(_width) << "Nick Name";
	std::cout << "|";
	std::cout << "\n";
	std::cout << "---------------------------------------------\n";
	for (size_t i = 0; i < this->getSize(); i++)
	{
		std::cout << "|";
		std::cout << std::right << std::setw(10) << i;
		std::cout << "|";
		std::cout << std::right << std::setw(10) << this->setWidth(this->contacts[i].getFirstName());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << this->setWidth(this->contacts[i].getLastName());
		std::cout << "|";
		std::cout << std::right << std::setw(10) << this->setWidth(this->contacts[i].getNickName());
		std::cout << "|";
		std::cout << "\n";
	}
	std::cout << "---------------------------------------------\n";
}

// NOTE: Private helper function
const std::string PhoneBook::setWidth(std::string _str) const
{
	if (_str.size() > 10)
	{
		_str.replace(9, _str.size(), ".");
		return (_str);
	}
	else
		return (_str);
}

// NOTE: Operator Overloading
PhoneBook& PhoneBook::operator = (const PhoneBook &_phonebook)
{
	this->size = _phonebook.size;
	for (size_t i = 0; i < _phonebook.size; i++) 
	{
		this->contacts[i] = _phonebook.contacts[i];
	}
	return (*this); // for Chaining
}

Contact& PhoneBook::operator [] (const int& _index)
{
	if (_index >= 0 && _index < static_cast<int>(this->size)) 
	{
		return (this->contacts[_index]);
	} 
	else 
	{
		std::cout << "Error : Index out of range" << "\n";
		exit(EXIT_FAILURE);
	}
}
