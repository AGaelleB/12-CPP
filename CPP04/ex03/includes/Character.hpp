// Character.hpp

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "main.hpp"
#include "Materia.hpp"
#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter {

	protected :
		std::string	_name;
		AMateria*	_materia[MaxNbMateria]; // Utiliser des pointeurs vers AMateria
		int			_nbMateria; // Pour suivre le nombre actuel d'objets dans l'inventaire

	public :
		 // construteur par default, de copie et destructeur
		Character();
		Character(std::string name);
		Character(const Character& rhs);
		virtual ~Character();

		// Opérateur d'affectation, surcharge d'operateur '='
		Character& operator=(const Character& rhs);

		// fonctions membres
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

};

#endif

