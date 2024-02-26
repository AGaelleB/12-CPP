#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp" 

class RobotomyRequestForm {

	private :
		std::string	_nameRobotomyRequestForm;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;

	public :
		// construteur par default, de copie et destructeur
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& name, int gradeToSign, int gradeToExecute);
		RobotomyRequestForm(const RobotomyRequestForm& rhs);
		~RobotomyRequestForm();

		// Opérateur d'affectation, surcharge d'operateur '='
		RobotomyRequestForm& operator=(const RobotomyRequestForm& rhs);

		// getters  & setters
		std::string	getNameRobotomyRequestForm() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;


		// fonctions memebres
		void		beSigned(const Bureaucrat& bureaucrat); // Méthode pour signer le RobotomyRequestFormulaire


		// exceptions
		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return("Grade is too high!");
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return("Grade is too low!");
				}
		};

};

// opérateur d'insertion <<
std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& RobotomyRequestForm);

#endif
