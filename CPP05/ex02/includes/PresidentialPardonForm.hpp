#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp" 

class PresidentialPardonForm {

	private :
		std::string	_namePresidentialPardonForm;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;

	public :
		// construteur par default, de copie et destructeur
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& name, int gradeToSign, int gradeToExecute);
		PresidentialPardonForm(const PresidentialPardonForm& rhs);
		~PresidentialPardonForm();

		// Opérateur d'affectation, surcharge d'operateur '='
		PresidentialPardonForm& operator=(const PresidentialPardonForm& rhs);

		// getters  & setters
		std::string	getNameForm() const;
		bool		getIsSigned() const;
		int			getGradeToSign() const;
		int			getGradeToExecute() const;


		// fonctions memebres
		void		beSigned(const Bureaucrat& bureaucrat); // Méthode pour signer le formulaire


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
std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& PresidentialPardonForm);

#endif
