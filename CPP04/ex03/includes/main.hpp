// main.hpp

#define RED			"\033[1;31m"
#define GREEN		"\033[1;32m"
#define YELLOW		"\033[1;33m"
#define BLUE		"\033[1;34m"
#define MAGENTA		"\033[1;35m"
#define CYAN		"\033[1;36m"
#define BOLD_WHITE	"\033[1;37m"
#define RESET		"\033[0m"

#include <iostream>
#include <string>

#define MaxNbMateria 4

/* PREFIXE
	Prefixe A : Abstraite -> pas instanciable 
	Prefixe I : Interface -> creer une interface 
 */

/* Exemple

	Imaginons un jeu vidéo où tu peux choisir différents types de personnages, comme un sorcier
	ou un guerrier. Chaque type de personnage peut faire des choses spéciales, comme lancer des
	sorts ou manier des épées. Mais il y a aussi des actions que tous les personnages doivent
	pouvoir faire, comme se déplacer ou attaquer, bien que la façon dont ils le font puisse varier.

 */

/* Classe Abstraite

	Classe Abstraite : C'est comme une idée générale d'un personnage. Elle dit "tout personnage doit
	pouvoir faire certaines choses" mais ne dit pas comment. Par exemple, elle pourrait dire que tout
	personnage doit pouvoir attaquer, mais un sorcier attaque en lançant des sorts tandis qu'un guerrier
	attaque avec son épée. La classe abstraite est comme un modèle que chaque type de personnage doit
	suivre, mais elle ne peut pas être utilisée directement dans le jeu parce qu'elle est trop générale.
 */

/* Méthode Virtuelle Pure

	Méthode Virtuelle Pure : C'est une action que la classe abstraite dit que tu dois pouvoir faire,
	mais sans dire comment. C'est comme si elle disait "ici, tu dois remplir les détails". Si la classe
	abstraite est une recette, la méthode virtuelle pure est un ingrédient que tu dois ajouter, mais elle
	ne te dit pas lequel; tu choisis en fonction du type de personnage (sorcier, guerrier, etc.) que tu crées.

 */

/* Classe Concrète

	Classe Concrète : C'est une version spécifique d'un personnage dans le jeu, comme un sorcier ou un
	guerrier. Elle prend l'idée générale de la classe abstraite et dit exactement comment les actions
	doivent être faites. Par exemple, elle expliquera comment le sorcier lance ses sorts ou comment le
	guerrier utilise son épée. C'est le type de personnage que tu peux vraiment choisir et jouer dans le jeu.

 */

/* Interface

	Interface : C'est comme une promesse. L'interface dit "peu importe qui tu es, si tu veux être considéré
	comme ce type de personnage, tu dois pouvoir faire ces actions". Par exemple, une interface pour des
	personnages qui peuvent se soigner dirait simplement "tu dois pouvoir te soigner", mais elle ne dirait
	pas comment. Les personnages qui peuvent se soigner (comme certains sorciers) diront alors comment ils
	font cela, en suivant la promesse de l'interface.

 */

/* Resumé

	Donc, en résumé, une classe abstraite donne l'idée générale, la méthode virtuelle pure demande les
	détails spécifiques, la classe concrète fournit ces détails, et une interface est comme une promesse
	que certains détails seront là.

 */


