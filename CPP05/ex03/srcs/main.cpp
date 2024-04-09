#include "../includes/Bureaucrat.hpp"
#include "../includes/AForm.hpp"
#include "../includes/PresidentialPardonForm.hpp"
#include "../includes/RobotomyRequestForm.hpp"
#include "../includes/ShrubberyCreationForm.hpp"
#include "../includes/Intern.hpp"
#include "../includes/main.hpp"

void	subjectMain (void) {

	try {
		std::cout << GREEN << "		~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Je cree un nvlle intern
		std::cout << BLUE << "-> Intern have been created" << RESET << std::endl;
		Intern	someRandomIntern;
		AForm*	rrf;

		rrf = someRandomIntern.makeForm("robotomy request", "Bender");

	}
	catch (const std::exception& exception) {
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}
}

void	myMain (void) {

	try {
		std::cout << GREEN << "      ~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Creating an intern
		std::cout << BLUE << "-> Intern has been created" << RESET << std::endl;
		Intern intern;

		// Creating a bureaucrat
		std::cout << BLUE << "-> Employee has been created" << RESET << std::endl;
		Bureaucrat bureaucratA("Gaga", 45);
		std::cout << bureaucratA << std::endl << std::endl;

		// Using the intern to create forms
		std::cout << BLUE << "-> Intern creates forms" << RESET << std::endl;
		AForm* form1;
		AForm* form2;
		AForm* form3;
		AForm* form4;

		form1 = intern.makeForm("ShrubberyCreationForm", "Tree");		// sign 145, exec 137
		form2 = intern.makeForm("RobotomyRequestForm", "Labo");			// sign 72, exec 45
		form3 = intern.makeForm("PresidentialPardonForm", "President");	// sign 25, exec 5
		form4 = intern.makeForm("Election", "President");				// n'existe pas

		// Checking if forms were created successfully
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		std::cout << std::endl;

		// Signing the forms
		std::cout << BLUE << "-> " << bureaucratA.getName() << " tries to sign the forms" << RESET << std::endl;
		bureaucratA.signForm(*form1);
		bureaucratA.signForm(*form2);
		bureaucratA.signForm(*form3);
		std::cout << std::endl;

		// Updating form status
		std::cout << BLUE << "-> Update" << RESET;
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl << std::endl;

		// Executing the forms
		std::cout << BLUE << "-> Execution after signature" << RESET << std::endl;
		bureaucratA.executeForm(*form1);
		std::cout << std::endl;
		bureaucratA.executeForm(*form2);
		std::cout << std::endl;
		bureaucratA.executeForm(*form3);
		std::cout << std::endl;

		// Cleaning up dynamically allocated memory
		delete form1;
		delete form2;
		delete form3;
		delete form4;
	}
	catch (const std::exception& exception) {
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}
	
}

int	main (void) {

	// subjectMain();
	myMain();

	return (0);
}


