#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

#include "Bureaucrat.hpp" 

class AForm {

	private :
		std::string	_nameForm;
		bool		_isSigned;
		int			_gradeToSign;
		int			_gradeToExecute;

	public :
		// construteur par default, de copie et destructeur
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& rhs);
		~AForm();

		// Opérateur d'affectation, surcharge d'operateur '='
		AForm& operator=(const AForm& rhs);

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
std::ostream& operator<<(std::ostream& os, const AForm& AForm);

#endif
