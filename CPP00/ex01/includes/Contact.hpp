#ifndef CONTACT_H
# define CONTACT_H

#include <iostream>
#include <string>

#include "../includes/PhoneBook.hpp"

class Contact {

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickname;
		unsigned long int	_phoneNumber;
		std::string _darkestSecret;
		int			_index;


	public:
		// constructor et destructor
		Contact(void);
		~Contact(void);

		// Getters
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		unsigned long int	getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
		int getIndex(void) const;

		// Setters
		void setFirstName(std::string userInput);
		void setLastName(std::string userInput);
		void setNickname(std::string userInput);
		void setPhoneNumber(unsigned long int userInput);
		void setDarkestSecret(std::string userInput);
		void setIndex(int userInput);
};
// objets contacts, qui doivent être chacun une instance de la classe Contact
 
#endif