// Character.hpp

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "main.hpp"
#include "AMateria.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

	private :
		std::string	_name;
		AMateria*	_materia[MaxNbMateria];
		int			_nbMateria; // Pour suivre le nb actuel d'objets dans l'inventaire

	public :
		 // construteur par default, de copie et destructeur
		Character();
		Character(std::string name);
		Character(const Character& rhs);
		~Character();

		// Opérateur d'affectation, surcharge d'operateur '='
		Character& operator=(const Character& rhs);

		// fonctions membres
		std::string const & getName() const;
		void equip(AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);

};

#endif

