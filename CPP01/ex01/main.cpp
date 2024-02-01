#include "Zombie.hpp"
#include <iostream>

int main() {

	int N = 42; // ici modifier pour le nbr de la horde

	if (N > 0) {
		Zombie *horde;
		horde = zombieHorde(N, "Gaga");
		for (int i = 0; i < N; i++) {
			horde[i].announce();
		}
		delete [] horde;
	}
	else {
		std::cout << "Error : must be positive integer" << std::endl;
		return (-1);
	}

	return 0;
}
