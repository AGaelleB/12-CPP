#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

class	AForm;

class Bureaucrat {

	private :
		std::string	_name;
		int			_grade;

	public :
		// construteur par default, de copie et destructeur
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& rhs);
		~Bureaucrat();

		// Opérateur d'affectation, surcharge d'operateur '='
		Bureaucrat& operator=(const Bureaucrat& rhs);

		// getters  & setters
		std::string	getName() const;
		int			getGrade() const;

		// fonctions memebres
		void		incrementGrade();
		void		decrementGrade();
		void		signForm(AForm & fm) const; // Check if the form got signed
		void		executeForm(AForm const & form); 
		// exceptions
		class GradeTooHighException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return("Grade cannot be incremented. Already at the highest grade!");
				}
		};

		class GradeTooLowException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return("Grade cannot be decremented. Already at the lowest grade!");
				}
		};

};

// opérateur d'insertion <<
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif

