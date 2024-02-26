#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {

	private :
		std::string	_target;

	public :
		// construteur par default, de copie et destructeur
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		virtual ~RobotomyRequestForm();

		// Opérateur d'affectation, surcharge d'operateur '='
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		// getter
		std::string getTarget() const;

		// fonctions membres
		void	execute(Bureaucrat const & executor) const ;

};

#endif
