#include "../includes/Intern.hpp"
#include "../includes/main.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Intern::Intern() {
	std::cout << CYAN << "~Intern~ default constructor called" << RESET << std::endl;
}

Intern::Intern(const Intern& rhs) {
	std::cout << CYAN << "~Intern~ copy constructor called" << RESET << std::endl;
}

Intern::~Intern() {
	std::cout << RED << "~Intern~ destructor called" << RESET << std::endl;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Intern& Intern::operator=(const Intern& rhs) {
	(void)rhs;
	return *this;
}


/****************************** FONCTIONS MEMBRES ******************************/


AForm* Intern::makeForm(std::string& nameOfTheForm, std::string& targetOfTheForm) {
	static const char* formNames[] = {
		"robotomy request",
		"presidential pardon",
		"shrubbery creation"
	};

	static AForm* forms[] = {
		new RobotomyRequestForm(targetOfTheForm),
		new PresidentialPardonForm(targetOfTheForm),
		new ShrubberyCreationForm(targetOfTheForm)
	};

	for (int i = 0; i < 3; ++i) {
		if (nameOfTheForm == formNames[i]) {
			std::cout << "Intern creates \"" << formNames[i] << "\"" << std::endl;
			return forms[i];
		}
	}

	std::cout << "Intern cannot create " << nameOfTheForm << " form" << std::endl;
	return NULL;
}