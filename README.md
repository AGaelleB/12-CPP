https://elearning.intra.42.fr/notions/piscine-c-d00-c-basics/subnotions

www.cplusplus.com


1. les names spaces

permet de regrouper des symboles et fonctions.

namespace new {
	int gl_var = 3;
	int (void) return 4;
}

les names spaces permet d avoir des fonctions du meme nom a l interieure de namespaces differents. On peut aussi imbriquer des namespaces.

operateur de resolution de portee ??


2. les flux d entrees sorties (streams)

std::cout << "test" << std::endl;


std::cout

std::endl pour le retour a la ligne 
<< et >>


3. les classes et instances 

les objets = les class


4. les attributs membres et fonctions membres 

5. les notions d'encapsulation (private/public)

6. les notions d'assesors



# ***************************** GPT *****************************

# Classes et Instances

## Classes :

Une classe en C++ est un modèle ou un blueprint pour créer des objets.
Elle définit un type de données en encapsulant des données et des fonctions qui opèrent sur ces données.
La classe spécifie quels seront les attributs (variables) et les comportements (fonctions ou méthodes) que les objets créés à partir de la classe auront.

## Instances :

Lorsqu'on crée un objet d'une classe, cet objet est appelé une instance de cette classe.
Chaque instance a son propre ensemble de variables d'instance (attributs), bien qu'elles partagent toutes la même description (la classe).
Par exemple, si vous avez une classe Voiture, chaque objet Voiture que vous créez est une instance distincte de cette classe.


# Notions de Base en C++

## Variables et Types de Données :

Les variables sont des espaces de stockage qui contiennent des données pouvant être modifiées pendant l'exécution du programme.
Les types de données courants incluent int, float, double, char, etc.
Fonctions :

Les fonctions sont des blocs de code qui effectuent une tâche spécifique.
En C++, une fonction est définie avec un nom, un type de retour, et des paramètres (optionnels).
Pointeurs :

Les pointeurs sont des variables qui stockent l'adresse d'une autre variable.
Ils sont très utiles en C++ pour la gestion dynamique de la mémoire et pour manipuler des tableaux et des structures.
Références :

Une référence est une sorte de pointeur qui ne peut jamais être nul et ne peut pas être réaffecté après sa définition.
Elle offre une autre façon de passer des objets à des fonctions.
Héritage :

L'héritage permet à une classe (classe dérivée) d'hériter des attributs et méthodes d'une autre classe (classe de base).
Cela permet la réutilisation de code et une hiérarchie de classes.
Polymorphisme :

Le polymorphisme permet d'utiliser une interface commune pour de multiples formes (types de données).
En C++, il est principalement réalisé par des fonctions virtuelles et l'héritage.
Encapsulation :

L'encapsulation consiste à cacher les détails internes d'une classe et à exposer seulement ce qui est nécessaire.
Elle est réalisée grâce à l'utilisation de modificateurs d'accès comme private, public, et protected.
Gestion de la Mémoire :

En C++, la gestion de la mémoire est cruciale, avec des opérations explicites pour l'allocation (new) et la libération (delete) de mémoire.
Ces concepts forment la base de la programmation orientée objet en C++, un paradigme qui facilite la création de programmes complexes et maintenables.
