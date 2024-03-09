// Cure.hpp

#ifndef CURE_HPP
#define CURE_HPP

#include "main.hpp"
#include "AMateria.hpp"

class ICharacter;

class Cure : public AMateria {

	public :
		 // construteur par default, de copie et destructeur
		Cure();
		Cure(const Cure& rhs);
		virtual ~Cure();

		// Opérateur d'affectation, surcharge d'operateur '='
		Cure& operator=(const Cure& rhs);

		// fonctions membres
		std::string const & getType() const;
		Cure*				clone() const;
		void				use(ICharacter& target);
};

#endif

