#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>

#include "Bureaucrat.hpp"

class Form {

	private :
		const std::string	_nameForm;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

	public :
		// construteur par default, de copie et destructeur
		Form();
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form(const Form& rhs);
		~Form();

		// Opérateur d'affectation, surcharge d'operateur '='
		Form& operator=(const Form& rhs);

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
std::ostream& operator<<(std::ostream& os, const Form& Form);

#endif
