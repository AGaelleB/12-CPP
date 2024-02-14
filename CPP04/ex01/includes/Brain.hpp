#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

class Brain {

	private :
		std::string _ideas[100];

	public :
		 // construteur par default, de copie et destructeur
		Brain();
		Brain(const Brain& rhs);
		~Brain();

		// Opérateur d'affectation, surcharge d'operateur '='
		Brain& operator=(const Brain& rhs);

		// Fonctions membres
		std::string	getIdea(int index) const;
		void		setIdea(int index, const std::string idea);

};

#endif
