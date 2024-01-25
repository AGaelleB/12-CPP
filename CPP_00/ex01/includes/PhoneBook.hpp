#ifndef PHONEBOOK_H
# define PHONEBOOK_H

#include "../includes/Contact.hpp"

class PhoneBook {

	private:
		Contact _Contacts[8];
		int _contactCount;

	public:
		// appel des constructor et destructor 
		PhoneBook(void);
		~PhoneBook(void);

		void OpenPhoneBook(void) const;
		void AddContact(void);
		void DataContact(Contact &newContact);
		void SearchContact(void);
		void DisplayContact(void);
		void ExitContact(void);
};
// l’objet répertoire doit être une instance de la classe PhoneBook

#endif