// Ice.hpp

#ifndef ICE_HPP
#define ICE_HPP

#include "main.hpp"
#include "AMateria.hpp"

class ICharacter;

class Ice : public AMateria {

	public :
		 // construteur par default, de copie et destructeur
		Ice();
		Ice(const Ice& rhs);
		virtual ~Ice();

		// Opérateur d'affectation, surcharge d'operateur '='
		Ice& operator=(const Ice& rhs);

		// fonctions membres
		std::string const &	getType() const;
		Ice*				clone() const;
		void				use(ICharacter& target);
};

#endif

