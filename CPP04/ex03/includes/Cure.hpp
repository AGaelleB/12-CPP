// Cure.hpp

#ifndef CURE_HPP
#define CURE_HPP

#include "main.hpp"
#include "Materia.hpp"

class Cure : public AMateria {

	protected :
		std::string	_type;

	public :
		 // construteur par default, de copie et destructeur
		Cure();
		Cure(std::string const & type);
		Cure(const Cure& rhs);
		virtual ~Cure();

		// Opérateur d'affectation, surcharge d'operateur '='
		Cure& operator=(const Cure& rhs);

		// fonctions membres
		std::string const & getType() const; //Returns the materia type
		
		virtual Cure* clone() const;
		virtual void use(ICharacter& target);
};

#endif

