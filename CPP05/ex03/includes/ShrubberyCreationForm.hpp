#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {

	private :
		std::string	_target;

	public :
		// construteur par default, de copie et destructeur
		ShrubberyCreationForm();
		ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& rhs);
		virtual ~ShrubberyCreationForm();

		// Opérateur d'affectation, surcharge d'operateur '='
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& rhs);

		// getter
		std::string getTarget() const;

		// fonctions membres
		void	execute(Bureaucrat const & executor) const ;

};

#endif
