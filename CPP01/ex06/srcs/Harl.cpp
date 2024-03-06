#include "../includes/Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::_debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << MSG_DEBUG << std::endl << std::endl;
}

void Harl::_info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << MSG_INFO << std::endl << std::endl;
}

void Harl::_warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << MSG_WARNING << std::endl << std::endl;
}

void Harl::_error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout <<  MSG_ERROR << std::endl;
}

void Harl::complain(std::string level) {

	std::string	levelFunctions[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			printFromToLevel = -1;

	for (int i = 0; i < 4; i++) {
		if (levelFunctions[i] == level) {
			printFromToLevel = i;
			break ;
		}
	}
	switch (printFromToLevel) {
		case 0:
			this->_debug();
			printFromToLevel++;
		case 1:
			this->_info();
			printFromToLevel++;
		case 2:
			this->_warning();
			printFromToLevel++;
		case 3:
			this->_error();
			break;
		default:
			std::cout << MSG_ELSE << std::endl;
	}
	return ;
}
