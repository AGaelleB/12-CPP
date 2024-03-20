#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/main.hpp"

int	main (void) {

	try {
		std::cout << GREEN << "		~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Je cree une nvlle employée
		std::cout << BLUE << "-> Employee have been created" << RESET << std::endl;
		Bureaucrat bureaucratA("Gaga", 45);
		std::cout << bureaucratA << std::endl;

		// Création des formulaires
		std::cout << BLUE << "\n-> Form have been created" << RESET << std::endl;
		// Form	a = Form();							// class abstraite ne s execute plus
		// std::cout << a << "\n\n";
		ShrubberyCreationForm form1("Garden");		// sign 145, exec 137
		RobotomyRequestForm form2("Labo");			// sign 72, exec 45
		PresidentialPardonForm form3("Elysée"); 	// sign 25, exec 5
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl << std::endl;

		// Signature des formulaires
		std::cout << BLUE << "-> " << bureaucratA.getName() << " try to sign the forms" << RESET << std::endl;
		bureaucratA.signForm(form1);
		bureaucratA.signForm(form2);
		bureaucratA.signForm(form3);
		std::cout << std::endl;

		// status a jour
		std::cout << BLUE << "-> " "Update" << RESET;
		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl << std::endl;

		// execution des formulaires
		std::cout << BLUE << "-> " "execution after signature" << RESET << std::endl;
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


