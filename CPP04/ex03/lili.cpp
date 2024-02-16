// Materia.hpp

#ifndef MATERIA_HPP
#define MATERIA_HPP

#include "main.hpp"

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
		std::string const & getType() const; //Returns the materia type
		
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
};


class IMateriaSource {

	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif

// MateriaSource.hpp

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "main.hpp"

class MateriaSource : public IMateriaSource {

	protected :

	public :
		 // construteur par default, de copie et destructeur
		MateriaSource();
		MateriaSource(const MateriaSource& rhs);
		virtual ~MateriaSource();

		// Opérateur d'affectation, surcharge d'operateur '='
		MateriaSource& operator=(const MateriaSource& rhs);

		// fonctions membres
		
};


class IMateriaSource {

	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(MateriaSource*) = 0;
		virtual MateriaSource* createMateria(std::string const & type) = 0;
};


#endif

// Ice.hpp

#ifndef ICE_HPP
#define ICE_HPP

#include "main.hpp"

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

// Cure.hpp

#ifndef CURE_HPP
#define CURE_HPP

#include "main.hpp"

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

// Charactere.hpp

#ifndef CHARACTERE_HPP
#define CHARACTERE_HPP

#include "main.hpp"

class Charactere : public ICharactere {

	protected :
		std::string	_name;
		int			_items[4];
		int			_idx;

	public :
		 // construteur par default, de copie et destructeur
		Charactere();
		Charactere(const Charactere& rhs);
		virtual ~Charactere();

		// Opérateur d'affectation, surcharge d'operateur '='
		Charactere& operator=(const Charactere& rhs);

		// fonctions membres

};

class ICharactere {

	public :
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& target) = 0;
};

#endif

// main.hpp

#define RED		"\033[1;31m"
#define GREEN	"\033[1;32m"
#define YELLOW	"\033[1;33m"
#define BLUE	"\033[1;34m"
#define MAGENTA	"\033[1;35m"
#define CYAN	"\033[1;36m"
#define RESET	"\033[0m"

#include <iostream>

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Materia.hpp"
#include "MateriaSource.hpp"
