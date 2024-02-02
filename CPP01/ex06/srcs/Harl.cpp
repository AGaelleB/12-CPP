#include "../includes/Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug() {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << MSG_DEBUG << std::endl << std::endl;
}

void Harl::info() {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << MSG_INFO << std::endl << std::endl;
}

void Harl::warning() {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << MSG_WARNING << std::endl << std::endl;
}

void Harl::error() {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout <<  MSG_ERROR << std::endl << std::endl;
}

void Harl::complain(std::string level) {

	// Association de chaque niveau à sa fonction
	t_level levelFunctions[4] = {
		{"DEBUG", 0},
		{"INFO", 1},
		{"WARNING", 2},
		{"ERROR", 3}
	};

	bool found = false;  // Ajout d'un indicateur pour savoir si on a trouvé une correspondance

	// Recherche de la fonction correspondante au niveau donné
	for (int i = 0; i < 4; i++) {
		if (level == levelFunctions[i].level) {
			found = true;
			switch (i) {
				case 0:
					this->debug();
					break;
				case 1:
					this->info();
					break;
				case 2:
					this->warning();
					break;
				case 3:
					this->error();
					break;
				default:
					std::cout << "Error: " << MSG_LEVEL << std::endl;
			}
		}
	}

	// Si aucun niveau correspondant n'est trouvé
	if (!found) {
		std::cout << "Error: " << MSG_LEVEL << std::endl;
	}
}



/* NOTE EXPLICATIVE

	Au lieu d'utiliser une série de déclarations if et else if pour décider quelle
	action effectuer en fonction du level, j'utilise des pointeurs de fonction
	membres pour appeler la fonction appropriée en fonction du level spécifié.

	La partie clé de cette fonction est la struct LevelFunctionPair.
	Cette struct agit comme une sorte de dictionnaire qui associe chaque level
	(comme "DEBUG" ou "INFO") à la fonction membre correspondante de la classe Harl
	(comme Harl::debug ou Harl::info).

	Ensuite, nous créons un tableau levelFunctions de cette struct, où chaque élément
	du tableau contient un level et le pointeur vers la fonction membre correspondante.

	Puis on parcours le tableau pour associer en fonction de l'entrée utilisateur

 */