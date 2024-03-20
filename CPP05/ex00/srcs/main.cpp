#include "../includes/Bureaucrat.hpp"

/* INFO GRADE
	grade 1 is the highest one and 150 the lowest
 */


int	main (void) {

	try {
		std::cout << GREEN << "		~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Je cree deux nvx employés
		std::cout << BLUE << "-> Employees have been created" << RESET << std::endl;
		Bureaucrat	bureaucratA("Tom", 149);
		Bureaucrat	bureaucratB("Gaga", 2);
		Bureaucrat	defaultBureaucrat;

		// Incrémentation du grade
		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " has been promoted!!" << std::endl;
		bureaucratA.incrementGrade();
		std::cout << bureaucratA << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratB.getName() << " has been promoted!!" << std::endl;
		bureaucratB.incrementGrade();
		std::cout << bureaucratB << std::endl;

		// std::cout << std::endl;
		// std::cout << bureaucratB.getName() << " has been promoted!!" << std::endl;
		// bureaucratB.incrementGrade();
		// std::cout << bureaucratB << std::endl;

		// Décrémentation du grade
		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " made a mistake..." << std::endl;
		bureaucratA.decrementGrade();
		std::cout << bureaucratA << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratB.getName() << " made a mistake..." << std::endl;
		bureaucratB.decrementGrade();
		std::cout << bureaucratB << std::endl;

		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " made 2 new mistakes..." << std::endl;
		bureaucratA.decrementGrade();
		std::cout << bureaucratA << std::endl;
		bureaucratA.decrementGrade();
		std::cout << bureaucratA << std::endl;
	
	}
	catch (const std::exception& exception) {
		std::cerr << MAGENTA << "\nException caught: " << exception.what() << RESET << std::endl;
	}

	return (0);
}
