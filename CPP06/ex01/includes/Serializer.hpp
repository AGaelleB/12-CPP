#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

#include "Data.hpp"
#include "main.hpp"

class Serializer {

	private :
		Serializer(); // en privée pour ne pas que la class soit instanciable
		Serializer(const Serializer& rhs);
		~Serializer();
		Serializer& operator=(const Serializer& rhs);

	public :
		static uintptr_t	serialize(Data* ptr);
		static Data*		deserialize(uintptr_t raw);
};

#endif


/* 
	But de l'exo : 
	convertir les adresses mémoires des objets en entiers
	Cela permet de manipuler les données de manière plus flexible
	et de les rendre plus facilement accessibles ou transférables
 */