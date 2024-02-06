#include "../includes/Harl.hpp"

Harl::Harl() {
}

Harl::~Harl() {
}

void Harl::_debug() {
	std::cout << std::endl << MSG_DEBUG << std::endl << std::endl;
}

void Harl::_info() {
	std::cout << std::endl << MSG_INFO << std::endl << std::endl;
}

void Harl::_warning() {
	std::cout << std::endl << MSG_WARNING << std::endl << std::endl;
}

void Harl::_error() {
	std::cout << std::endl << MSG_ERROR << std::endl << std::endl;
}

void Harl::complain(std::string level) {

	// Association de chaque niveau à sa fonction
	t_level levelFunctions[4] = {
		{"DEBUG", &Harl::_debug},
		{"INFO", &Harl::_info},
		{"WARNING", &Harl::_warning},
		{"ERROR", &Harl::_error}
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
	action effectuer en fonction du level, j'utilise des pointeurs de fonction
	membres pour appeler la fonction appropriée en fonction du level spécifié.

	La partie clé de cette fonction est la struct t_level.
	Cette struct agit comme une sorte de dictionnaire qui associe chaque level
	(comme "_debug" ou "_info") à la fonction membre correspondante de la classe Harl
	(comme Harl::_debug ou Harl::_info).

	Ensuite, je cree un tableau levelFunctions de cette struct, où chaque élément
	du tableau contient un level et le pointeur vers la fonction membre correspondante.

	Puis je parcours le tableau pour associer en fonction de l'entrée utilisateur

 */