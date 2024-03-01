#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {

	private :
		std::string	_target;

	public :
		// construteur par default, de copie et destructeur
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		virtual ~PresidentialPardonForm();

		// Opérateur d'affectation, surcharge d'operateur '='
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		// getter
		std::string getTarget() const;

		// fonctions membres
		void	execute(Bureaucrat const & executor) const ;

};

#endif


