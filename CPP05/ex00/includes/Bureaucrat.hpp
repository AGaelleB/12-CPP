#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

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


/* LES EXECPTIONS

	try : Un bloc de code dans lequel des exceptions peuvent être lancées et où le programme tente de gérer ces exceptions.
	
	catch : Un bloc de code qui capture et gère les exceptions lancées dans un bloc try, permettant au programme de réagir
	de manière appropriée aux erreurs.
	
	what : Une méthode utilisée pour obtenir des informations sur l'erreur qui s'est produite, renvoyant une description
	de l'exception sous forme de chaîne de caractères, ce qui est utile pour le débogage et la journalisation des erreurs.

 */