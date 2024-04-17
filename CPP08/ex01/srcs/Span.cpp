#include "../includes/Span.hpp"


/************************* CONSTRUCTEURS ET DESTRUCTEUR  *************************/

Span::Span() : _numbers() {
	this->_maxSize = 0;
	return;
}

Span::Span(unsigned int N) {
	this->_maxSize = N;
	return;
}


Span::Span(const Span & obj) {
	*this = obj;
}

Span::~Span() {
	return;
}


/*************************** OPERATEUR D'AFFECTATION  **************************/

Span& Span::operator=(const Span & rhs) {
	if (this == &rhs)
		return *this;

	this->_maxSize = rhs._maxSize;
	this->_numbers = rhs._numbers;

	return *this;
}


/****************************** FONCTIONS MEMBRES ******************************/

void			Span::addNumber(int nb) {

	if (_numbers.size() >= _maxSize) {
		throw AddNumberException();
	}
	_numbers.push_back(nb); // ajoute du nb a la liste
}

unsigned int	Span::shortestSpan() const {

	if (_numbers.size() < 2)
		throw SearchSpanException();

	// je crée une copie du vecteur _numbers pour ne pas modifier l'original
	std::vector<int> sortednumbers = _numbers;

	// Je trie le vecteur en ordre croissant
	std::sort(sortednumbers.begin(), sortednumbers.end());

	// j initialise la diff min avec la diff entre les 2 premiers nb
	unsigned int minDifference = sortednumbers[1] - sortednumbers[0];

	// je parcours le vecteur pour trouver la diff min
	for (size_t i = 1; i < sortednumbers.size() - 1; ++i) {
		unsigned int difference = sortednumbers[i + 1] - sortednumbers[i];
		if (difference < minDifference) {
			minDifference = difference;
		}
	}
	return minDifference;
}

unsigned int	Span::longestSpan() const {

	if (_numbers.size() < 2)
		throw SearchSpanException();

	// Trouver le min et le max des nb stockés
	int minValue = *std::min_element(_numbers.begin(), _numbers.end());
	int maxValue = *std::max_element(_numbers.begin(), _numbers.end());

	// Calculer la diff entre le max et le min
	unsigned int maxDifference = maxValue - minValue;

	return (maxDifference);
}


void Span::addRange(const std::vector<int>& v) {
	// je vérifie si la taille finale dépasse maxSize
	if (_numbers.size() + v.size() > _maxSize) {
		throw AddNumberException();
	}
	// j insère tous les éléments du vecteur v dans _numbers
	_numbers.insert(_numbers.end(), v.begin(), v.end());
}
