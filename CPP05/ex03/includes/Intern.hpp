#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include <stdexcept> // For std::invalid_argument

#include "AForm.hpp"
#include "Intern.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
		Intern();
		Intern(const Intern& rhs);
		~Intern();

		Intern& operator=(const Intern& rhs);

		AForm* makeForm(std::string nameOfTheForm, std::string targetOfTheForm);
};


#endif
