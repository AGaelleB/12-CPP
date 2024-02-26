#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"


#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"


int	main (void) {

	try {
		std::cout << GREEN << "~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Je cree unr nvlle employée
		std::cout << BLUE << "A new employee has joined the company :" << RESET << std::endl;
		Bureaucrat bureaucratA("Gaga", 46);
		std::cout << bureaucratA << std::endl << std::endl;
		
		// Création des formulaires
		std::cout << BLUE "Form have been created" << RESET;

		ShrubberyCreationForm form1("Home");		// sign 145, exec 137
		RobotomyRequestForm form2("Labo");			// sign 72, exec 45
		PresidentialPardonForm form3("Elysée"); 	// sign 25, exec 5
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl << std::endl;

		// Signature des formulaires
		std::cout << BLUE << bureaucratA.getName() << " try to sign the forms" << RESET << std::endl;
		bureaucratA.signForm(form1);
		bureaucratA.signForm(form2);
		bureaucratA.signForm(form3);
		std::cout << std::endl;

		// status a jour
		std::cout << BLUE "Update" << RESET;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl << std::endl;

		// execution des formulaires
		std::cout << BLUE "execution after signature" << RESET << std::endl;
		bureaucratA.executeForm(form1);
		std::cout << std::endl;
		bureaucratA.executeForm(form2);
		std::cout << std::endl;
		bureaucratA.executeForm(form3);
		std::cout << std::endl;

	}
	catch (const std::exception& exception) {
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}


