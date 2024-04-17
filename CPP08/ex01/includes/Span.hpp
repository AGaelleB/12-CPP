#ifndef SPAN_HPP
# define SPAN_HPP

# include <algorithm>
# include <vector>
# include <iostream>

class Span {
	private:
		std::vector<int>	_numbers; // Utilisation d'un vecteur pour stocker les entiers
		unsigned int		_maxSize;

	public:
		// construteur par default, de copie et destructeur
		Span();
		Span(unsigned int N);
		Span(const Span & obj);
		~Span();

		// Opérateur d'affectation
		Span& operator=(const Span & rhs);

		// Fonctions membres
		void			addNumber(int nb);
		unsigned int	shortestSpan() const;
		unsigned int	longestSpan() const;
		void			addRange(const std::vector<int>& vector);

		// Exceptions
		class AddNumberException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "Failed to add number: size limit exceeded or number already added";
				}
		};

		class SearchSpanException : public std::exception {
			public :
				virtual const char* what() const throw() {
					return "No span found: no numbers stored or too few numbers to calculate";
				}
		};
};


#endif


