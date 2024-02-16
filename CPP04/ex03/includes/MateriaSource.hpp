// MateriaSource.hpp

/* A quoi ca sert cette class ?

	MateriaSource permet de : 
	- Stocker des "sort"
	- Apprendre des "sort"
	- Créer des "sort"

	C'est une fabrique et un répertoire de "sort"

 */


#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "main.hpp"
#include "Materia.hpp"

class AMateria;

class MateriaSource : public IMateriaSource {

	private :
		AMateria*	_materia[MaxNbMateria];
		int			_nbMateria;


	public :
		 // construteur par default, de copie et destructeur
		MateriaSource();
		MateriaSource(const MateriaSource& rhs);
		virtual ~MateriaSource();

		// Opérateur d'affectation, surcharge d'operateur '='
		MateriaSource& operator=(const MateriaSource& rhs);

		// fonctions membres
		// ???
};


class IMateriaSource {

	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif

