#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"


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

		// Je cree deux nvx employés
		std::cout << BLUE << "A new employee has joined the company :" << RESET << std::endl;
		Bureaucrat bureaucratA("Gaga", 51);
		std::cout << bureaucratA << std::endl << std::endl;
		
		// Création des formulaires
		std::cout << BLUE "Form have been created" << RESET;
		Form	formA = Form();
		Form	formB = Form("A21", 50, 10);
		std::cout << formA << std::endl;
		std::cout << formB << std::endl << std::endl;

		// Signature des formulaires
		std::cout << BLUE << bureaucratA.getName() << " try to sign the form" << RESET << std::endl;
		bureaucratA.signForm(formA);
		bureaucratA.signForm(formB);
		std::cout << std::endl;

		// status a jour
		std::cout << BLUE "Update" << RESET;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl << std::endl;

		// Incrémentation du grade
		std::cout << BLUE << bureaucratA.getName() << " has been promoted!!" << RESET << std::endl;
		bureaucratA.incrementGrade();
		std::cout << std::endl;

		// Signature des formulaires
		std::cout << BLUE << bureaucratA.getName() << " signed the form" << RESET << std::endl;
		bureaucratA.signForm(formB);
		std::cout << std::endl;

		// status a jour
		std::cout << BLUE "Update" << RESET;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	
	}
	catch (const std::exception& exception) {
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}
