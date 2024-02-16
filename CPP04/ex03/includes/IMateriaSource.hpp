// IMateriaSource.hpp

#ifndef IMATERIASOURCE_HPP
#define IMATERIASOURCE_HPP

#include "main.hpp"
#include "Materia.hpp"

class AMateria;

class IMateriaSource {

	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};


#endif

