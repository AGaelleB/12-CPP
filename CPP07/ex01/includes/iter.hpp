#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>


template<typename T>
void iter(T* array, int length, void (*func)(T&)) {
	for (int i = 0; i < length; ++i) {
		func(array[i]); // Appel de la fonction sur chaque élément de l'array
	}
}

template<typename T>
void printElement(T& element) {
	std::cout << element << " ";
}

#endif
