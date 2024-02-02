#include "../includes/SedProgram.hpp"

#include <iostream>

int main(int ac, char **av) {
	(void)av;

	if (ac != 4) {
		std::cout << "Error: wrong numbers of arguments" << std::endl;
		std::cout << "Must be: <filename> <s1_to_remplace> <by_s2>" << std::endl;
		return (-1);
	}
	else {
		SedProgram run;
		run.checkFilename(av[1]);
		run.checkAndRreplace(av[1], av[2], av[3]);
	}
	return 0;
}

