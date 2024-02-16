// Materia.hpp

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "main.hpp"

class ICharacter; // Inclusion de ICharacter dans Materia.hpp

class AMateria {

	protected :
		std::string	_type;

	public :
		 // construteur par default, de copie et destructeur
		AMateria();
		AMateria(std::string const & type);
		AMateria(const AMateria& rhs);
		virtual ~AMateria();

		// Opérateur d'affectation, surcharge d'operateur '='
		AMateria& operator=(const AMateria& rhs);

		// fonctions membres
		std::string const & getType() const;
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};

#endif

