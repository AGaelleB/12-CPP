#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

#include "AForm.hpp"

class Intern : public AForm {

	private :
		std::string	_target;

	public :
		// construteur par default, de copie et destructeur
		Intern();
		Intern(const std::string& target);
		Intern(const Intern& rhs);
		~Intern();

		// Opérateur d'affectation, surcharge d'operateur '='
		Intern& operator=(const Intern& rhs);

		// fonctions membres
		void	makeForm(std::string resquestForm, std::string formName) const ;

};

#endif
