#ifndef PHONEBOOK_H
# define PHONEBOOK_H

class PhoneBook {

	private:
		int	_Contacts[8];

	public:
		// int foo // un attribut

		// appel des constructor et destructor 
		PhoneBook(void);
		~PhoneBook(void);

		void OpenPhoneBook(void) const;
		void AddContact(void);
		void SearchContact(void);
		void PrintContact(void);
		void ExitContact(void);
};
// l’objet répertoire doit être une instance de la classe PhoneBook

#endif