#include "../includes/Bureaucrat.hpp"
#include "../includes/Form.hpp"
#include "../includes/main.hpp"

int	main (void) {

	try {
		std::cout << GREEN << "		~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Je cree deux nvx employés
		Bureaucrat bureaucratA("Gaga", 51);
		std::cout << bureaucratA << std::endl;

		// Création des formulaires
		std::cout << BLUE << "-> Form have been created" << RESET;
		Form	formA = Form();
		Form	formB = Form("A21", 50, 10);
		std::cout << formA << std::endl;
		std::cout << formB << std::endl << std::endl;

		// Signature des formulaires
		std::cout << BLUE << "-> " << bureaucratA.getName() << " try to sign the form" << RESET << std::endl;
		bureaucratA.signForm(formA);
		bureaucratA.signForm(formB);
		std::cout << std::endl;

		// status a jour
		std::cout << BLUE << "-> " "Update" << RESET;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl << std::endl;

		// Incrémentation du grade
		std::cout << BLUE << "-> " << bureaucratA.getName() << " has been promoted!!" << RESET << std::endl;
		bureaucratA.incrementGrade();
		std::cout << bureaucratA << std::endl;

		std::cout << std::endl;

		// Signature des formulaires
		std::cout << BLUE << "-> " << bureaucratA.getName() << " signed the form" << RESET << std::endl;
		bureaucratA.signForm(formB);
		std::cout << std::endl;

		// status a jour
		std::cout << BLUE << "-> Update" << RESET;
		std::cout << formA << std::endl;
		std::cout << formB << std::endl;
	
	}
	catch (const std::exception& exception) {
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}
