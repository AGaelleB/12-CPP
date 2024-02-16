// MateriaSource.hpp

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "main.hpp"
#include "Materia.hpp"

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

