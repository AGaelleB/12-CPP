#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
#include <vector>
#include <list>
#include <iostream>

class NoOccurrenceException : public std::exception {
	public:
		virtual const char* what() const throw() {
			return "No occurrence found";
		}
};

template <typename T>
typename T::iterator	easyfind(T& container , int value) {
	typename T::iterator it = std::find(container.begin(), container.end(), value);
	if (it == container.end()) {
		throw NoOccurrenceException();
	}
	return it;
}

#endif


/*
	typename T::iterator	easyfind(T& container , int value)

	cette ligne de code déclare une variable it de type itérateur pour le conteneur passé à la fonction,
	puis elle utilise std::find pour chercher une valeur spécifique dans ce conteneur.
	Si la valeur est trouvée, it pointe vers cette valeur ; sinon, it pointe vers la fin du conteneur,
	indiquant que la valeur n'a pas été trouvée.
 */