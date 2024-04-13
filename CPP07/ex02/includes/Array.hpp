#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>

template<typename T>
class Array {

	private:
		T*				_elements; // Tableau pour stocker les éléments de type T
		unsigned int	_size;

		class	ArrayIndexOutOfBoundsException: public std::exception
				{
					public:
						virtual const char *what() const throw() {
							return ("Index is out of range");
						}
				};


	public:
		// Constructeurs
		Array() : _elements(0), _size(0) {} // Constructeur par défaut (tableau vide)

		Array(unsigned int n) : _size(n) {
			_elements = new T[_size]; // Alloue la mémoire pour le tableau
			for (unsigned int i = 0; i < _size; i++) {
				_elements[i] = T(); // Appelle le constructeur par défaut de T
			}
		}

		// Constructeur par copie
		Array(const Array<T>& rhs) : _size(rhs._size) {
			_elements = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_elements[i] = rhs._elements[i];
			}
		}

		// Opérateur d'affectation
		Array<T>& operator=(const Array<T>& rhs) {
			if (this != &rhs) {
				delete[] _elements; // Libère la mémoire du tableau actuel
				_size = rhs._size;
				_elements = new T[_size];
				for (unsigned int i = 0; i < _size; i++) {
					_elements[i] = rhs._elements[i]; // Copie des éléments de l'autre tableau
				}
			}
			return *this;
		}

		// Destructeur
		~Array() {
			delete[] _elements;
		}

		// Opérateur de sous-script [] permet d'acceder a un index du tableau
		T& operator[](unsigned int index) {
			if (index >= _size) {
				throw ArrayIndexOutOfBoundsException();
			}
			return _elements[index];
		}

		const T& operator[](unsigned int index) const {
			if (index >= _size) {
				throw ArrayIndexOutOfBoundsException();
			}
			return _elements[index];
		}

		// Fonction size()
		unsigned int size() const {
			return _size;
		}
};

#endif