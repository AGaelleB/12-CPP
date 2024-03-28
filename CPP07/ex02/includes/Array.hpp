#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception> // pour mon heritage dans l exeption

template<typename T>
class Array {

	private:
		T*				elements; // Tableau pour stocker les éléments de type T
		unsigned int	size; // Taille du tableau

		class	ArrayIndexOutOfBoundsException: public std::exception
				{
					public:
						virtual const char *what() const throw() {
							return ("Index is out of range");
						}
				};


	public:
		// Constructeurs
		Array() : elements(0), size(0) {} // Constructeur par défaut (tableau vide)

		Array(unsigned int n) : size(n) {
			elements = new T[size]; // Alloue la mémoire pour le tableau
			for (unsigned int i = 0; i < size; i++) {
				elements[i] = T(); // Appelle le constructeur par défaut de T
			}
		}

		// Constructeur par copie
		Array(const Array<T>& rhs) : size(rhs.size) {
			elements = new T[size];
			for (unsigned int i = 0; i < size; i++) {
				elements[i] = rhs.elements[i];
			}
		}

		// Opérateur d'affectation
		Array<T>& operator=(const Array<T>& rhs) {
			if (this != &rhs) {
				delete[] elements; // Libère la mémoire du tableau actuel
				size = rhs.size;
				elements = new T[size];
				for (unsigned int i = 0; i < size; i++) {
					elements[i] = rhs.elements[i]; // Copie des éléments de l'autre tableau
				}
			}
			return *this;
		}

		// Destructeur
		~Array() {
			delete[] elements;
		}

		// Opérateur de sous-script [] permet d'acceder a un index du tableau
		T& operator[](unsigned int index) {
			if (index >= size) {
				throw ArrayIndexOutOfBoundsException(); 
			}
			return elements[index];
		}

		// Fonction size()
		unsigned int getSize() const {
			return size;
		}
};

#endif