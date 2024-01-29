#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "../includes/Contact.hpp"

class PhoneBook {

	private:
		Contact _PhoneBook[8];
		int _contactCount;
		int _nextIndex; 

	public:
		// appel des constructor et destructor 
		PhoneBook(void);
		~PhoneBook(void);

		void OpenPhoneBook(void) const;
		void AddContact(void);
		void DataContact(Contact &newContact);
		void SearchContact(void);
		void DisplayAllContacts(void);
		std::string TruncateString(const std::string input, size_t maxLength);
		void DisplayContactIndex(int userInput);
		void ExitContact(void);
};
// l’objet répertoire doit être une instance de la classe PhoneBook

#endif