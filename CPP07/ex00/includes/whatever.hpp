#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>

template <typename T>
class whatever {

	public :
		void		swap(T& a, T& b);
		T const&	min(T const& a, T const& b);
		T const&	max(T const& a, T const& b);
};

template <typename T>
void swap(T& a, T& b) {
	T	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const& min(T const &nb1, T const &nb2) {
	if (nb1 < nb2)
		return (nb1);
	return (nb2);
}

template<typename T>
T const& max(T const &nb1, T const &nb2) {
	if (nb1 > nb2)
		return (nb1);
	return (nb2);
}

#endif