#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array {

	private:
		T* elements; // Tableau pour stocker les éléments de type T
		unsigned int size; // Taille du tableau

	public:
		// Constructeurs
		Array() : elements(0), size(0) {} // Constructeur par défaut (tableau vide)

		Array(unsigned int n) : size(n) {
			elements = new T[size]; // Alloue la mémoire pour le tableau
			// Initialise les éléments par défaut
			for (unsigned int i = 0; i < size; ++i) {
				elements[i] = T(); // Appelle le constructeur par défaut de T
			}
		}

		// Constructeur par copie
		Array(const Array<T>& other) : size(other.size) {
			elements = new T[size];
			for (unsigned int i = 0; i < size; ++i) {
				elements[i] = other.elements[i]; // Copie des éléments de l'autre tableau
			}
		}

		// Opérateur d'affectation
		Array<T>& operator=(const Array<T>& other) {
			if (this != &other) { // Vérifie que ce n'est pas la même instance
				delete[] elements; // Libère la mémoire du tableau actuel
				size = other.size;
				elements = new T[size];
				for (unsigned int i = 0; i < size; ++i) {
					elements[i] = other.elements[i]; // Copie des éléments de l'autre tableau
				}
			}
			return *this;
		}

		// Destructeur
		~Array() {
			delete[] elements;
		}

		// Opérateur de sous-script []
		T& operator[](unsigned int index) {
			if (index >= size) {
				throw std::out_of_range("Index is out of range");
			}
			return elements[index];
		}

		// Fonction size()
		unsigned int getSize() const {
			return size;
		}
};

#endif