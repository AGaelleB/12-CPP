#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP


# include <stack>
# include <vector>
# include <iostream>


template<typename T>
class MutantStack : public std::stack<T> { // heritage pour l'itération

	public:
		// Typedef pour les types d'itérateurs standards et inverses
		typedef typename std::deque<T>::iterator iterator;
		typedef typename std::deque<T>::const_iterator const_iterator;
		typedef typename std::deque<T>::reverse_iterator reverse_iterator;
		typedef typename std::deque<T>::const_reverse_iterator const_reverse_iterator;

		// Constructeur par défaut, de copie et destructeur
		MutantStack();
		MutantStack(const MutantStack& rhs);
		virtual ~MutantStack();

		// Opérateur d'affectation
		MutantStack& operator=(const MutantStack& rhs);

		// Itérateurs standards
		iterator				begin();
		iterator				end();
		const_iterator			begin() const;
		const_iterator			end() const;
		
		// Itérateurs inverses
		reverse_iterator		rbegin();
		reverse_iterator		rend();
		const_reverse_iterator	rbegin() const;
		const_reverse_iterator	rend() const;
};


// Fonctions membres

template<typename T>
MutantStack<T>::MutantStack() : std::stack<T>() {}

template<typename T>
MutantStack<T>::MutantStack(const MutantStack<T>& rhs) : std::stack<T>(rhs) {}

template<typename T>
MutantStack<T>::~MutantStack() {}

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T>& rhs) {
	if (this != &rhs) {
		std::stack<T>::operator=(rhs);
	}
	return *this;
}


// Méthodes pour obtenir des itérateurs au début et à la fin du conteneur

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin() {
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::iterator MutantStack<T>::end() {
	return std::stack<T>::c.end();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::begin() const {
	return std::stack<T>::c.begin();
}

template<typename T>
typename MutantStack<T>::const_iterator MutantStack<T>::end() const {
	return std::stack<T>::c.end();
}


// Méthodes pour obtenir des itérateurs inverses au début et à la fin du conteneur

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rbegin() {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::reverse_iterator MutantStack<T>::rend() {
	return this->c.rend();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rbegin() const {
	return this->c.rbegin();
}

template<typename T>
typename MutantStack<T>::const_reverse_iterator MutantStack<T>::rend() const {
	return this->c.rend();
}


#endif // MUTANTSTACK_HPP
