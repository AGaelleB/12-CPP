#include "../includes/Bureaucrat.hpp"

/* INFO GRADE
	grade 1 is the highest one and 150 the lowest
 */


int	main (void) {

	try {
		std::cout << GREEN << "~~~ Welcome to the company! ~~~\n" << RESET << std::endl;

		// Je cree deux nvz employés
		Bureaucrat bureaucratA("Tom", 149);
		std::cout << "A new employee has joined the company :" << std::endl;
		std::cout << bureaucratA << std::endl;
		
		Bureaucrat bureaucratB("Gaga", 2);
		std::cout << "\nA new employee has joined the company :" << std::endl;
		std::cout << bureaucratB << std::endl;



		// Incrémentation du grade
		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " has been promoted!!" << std::endl;
		bureaucratA.incrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratB.getName() << " has been promoted!!" << std::endl;
		bureaucratB.incrementGrade();



		// Décrémentation du grade
		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " made a mistake..." << std::endl;
		bureaucratA.decrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratB.getName() << " made a mistake..." << std::endl;
		bureaucratB.decrementGrade();

		std::cout << std::endl;
		std::cout << bureaucratA.getName() << " made 2 new mistakes..." << std::endl;
		bureaucratA.decrementGrade();
		bureaucratA.decrementGrade();
	
	}
	catch (const std::exception& exception) {
		std::cerr << "Exception caught: " << exception.what() << std::endl;
	}

	return (0);
}

