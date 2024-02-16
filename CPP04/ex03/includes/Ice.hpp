// Ice.hpp

#ifndef ICE_HPP
#define ICE_HPP

#include "main.hpp"
#include "Materia.hpp"

class Ice : public AMateria {

	protected :
		std::string	_type;

	public :
		 // construteur par default, de copie et destructeur
		Ice();
		Ice(std::string const & type);
		Ice(const Ice& rhs);
		virtual ~Ice();

		// Opérateur d'affectation, surcharge d'operateur '='
		Ice& operator=(const Ice& rhs);

		// fonctions membres
		std::string const & getType() const; //Returns the materia type
		
		virtual Ice* clone() const;
		virtual void use(ICharacter& target);
};

#endif

