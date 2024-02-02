#include "../includes/Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::debug() {
	std::cout << std::endl << MSG_DEBUG << std::endl << std::endl;
}

void Harl::info() {
	std::cout << std::endl << MSG_INFO << std::endl << std::endl;
}

void Harl::warning() {
	std::cout << std::endl << MSG_WARNING << std::endl << std::endl;
}

void Harl::error() {
	std::cout << std::endl << MSG_ERROR << std::endl << std::endl;
}

void Harl::complain(std::string level) {

	// Définition d'une struct pour associer un niveau à une fonction membre
	struct LevelFunctionPair {
		std::string level;
		void (Harl::*function)();
	};

	// Association de chaque niveau à sa fonction
	LevelFunctionPair levelFunctions[4] = {
		{"DEBUG", &Harl::debug},
		{"INFO", &Harl::info},
		{"WARNING", &Harl::warning},
		{"ERROR", &Harl::error}
	};

	// Je parcours le tab pour trouver la fonction correspondante au niveau donné
	for (int i = 0; i < 4; i++) {
		if (level == levelFunctions[i].level) {
			(this->*(levelFunctions[i].function))();
			return;
		}
	}
	std::cout << "Error: " MSG_LEVEL << std::endl;
}

/* NOTE EXPLICATIVE

	 Au lieu d'utiliser une série de déclarations if et else if pour décider quelle
	action effectuer en fonction du niveau, nous utilisons des pointeurs de fonction
	membres pour appeler la fonction appropriée en fonction du niveau spécifié.

	La partie clé de cette fonction est la structure LevelFunctionPair.
	Cette structure agit comme une sorte de dictionnaire qui associe chaque niveau
	(comme "DEBUG" ou "INFO") à la fonction membre correspondante de la classe Harl
	(comme Harl::debug ou Harl::info).

	Ensuite, nous créons un tableau levelFunctions de cette structure, où chaque
	élément du tableau contient un niveau et le pointeur vers la fonction membre
	correspondante.

	Puis on parcours le tableau pour associer en fonction de l'entrée utilisateur

 */