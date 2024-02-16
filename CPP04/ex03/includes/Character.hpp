#ifndef CHARACTERE_HPP
#define CHARACTERE_HPP

#include "main.hpp"

class Charactere : public ICharactere {

	protected :
		std::string	_type;
		int			_items[4];
		int			_index;

	public :
		 // construteur par default, de copie et destructeur
		Charactere();
		Charactere(std::string const & type);
		Charactere(const Charactere& rhs);
		virtual ~Charactere();

		// Opérateur d'affectation, surcharge d'operateur '='
		Charactere& operator=(const Charactere& rhs);

		// fonctions membres
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

class ICharactere {

	public :
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif

