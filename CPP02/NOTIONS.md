
# forme canonique de Coplien

La forme canonique de Coplien, est une convention de conception de classes en C++ qui recommande d'implémenter trois méthodes spécifiques dans une classe lorsque l'une d'entre elles est nécessaire. Ces trois méthodes sont le **constructeur de copie**, **l'opérateur d'affectation** et **le destructeur**. 
Pour ce module de 42 il faudra aussi ajouter **le constructeur par défaut**.


## Constructeur par défaut :

Un constructeur par défaut est une méthode spéciale qui est appelée lorsqu'un objet est créé sans arguments. Il initialise les membres de l'objet avec des valeurs par défaut. Par exemple, si vous avez une classe représentant une voiture, le constructeur par défaut pourrait initialiser la voiture avec des valeurs par défaut comme le modèle "inconnu" et la vitesse "0".

## Constructeur de recopie :

Le constructeur de recopie est utilisé pour créer une copie d'un objet existant. Il est appelé lorsqu'un objet est passé par valeur à une fonction, lorsqu'un nouvel objet est initialisé à partir d'un objet existant, ou lorsqu'un objet est retourné par valeur à partir d'une fonction.

## Opérateur d'affectation :

L'opérateur d'affectation (=) est utilisé pour copier les valeurs d'un objet vers un autre objet déjà existant. Il est appelé lorsqu'un objet est affecté à un autre à l'aide de l'opérateur d'affectation.

## Destructeur :

Le destructeur est une méthode spéciale appelée lorsqu'un objet est détruit, généralement à la fin de son cycle de vie. C'est l'endroit où vous libérez les ressources allouées, telle que la mémoire, utilisées par l'objet. Il est défini avec le symbole ~ suivi du nom de la classe.
En suivant la forme canonique de Coplien, vous garantissez une gestion correcte de la mémoire, une copie appropriée des objets et une assignation correcte entre eux, contribuant ainsi à la robustesse et à la cohérence de votre code.

## Exemple mise en pratique :

1. **Constructeur par défaut (Car())** :
Initialise une voiture avec un modèle par défaut "Unknown" et une vitesse de 0 km/h.

2. **Constructeur avec paramètres** (Car(const std::string&, int)) :
Permet de créer une voiture avec un modèle et une vitesse spécifiés.

3. **Constructeur de copie (Car(const Car&))** :
Utilisé pour créer une copie d'une voiture existante.

4. **Opérateur d'affectation (Car& operator=(const Car&))** :
Permet d'assigner une voiture existante à une autre.

5. **Destructeur (~Car())** :
Libère les ressources allouées à la destruction de l'objet.

6. **Fonction displayDetails()** :
Affiche les détails de la voiture.


Dans la fonction main(), vous pouvez voir comment ces fonctions sont utilisées pour créer, copier, affecter et détruire des objets de la classe Car.

```cpp
#include <iostream>
#include <string>

class Car {
private:
    std::string model;
    int speed;

public:
    // Constructeur par défaut
    Car() : model("Unknown"), speed(0) {
        std::cout << "Constructeur par défaut appelé." << std::endl;
    }

    // Constructeur avec paramètres
    Car(const std::string& carModel, int carSpeed) : model(carModel), speed(carSpeed) {
        std::cout << "Constructeur avec paramètres appelé." << std::endl;
    }

    // Constructeur de copie
    Car(const Car& other) : model(other.model), speed(other.speed) {
        std::cout << "Constructeur de copie appelé." << std::endl;
    }

    // Opérateur d'affectation
    Car& operator=(const Car& other) {
        if (this != &other) {
            model = other.model;
            speed = other.speed;
            std::cout << "Opérateur d'affectation appelé." << std::endl;
        }
        return *this;
    }

    // Destructeur
    ~Car() {
        std::cout << "Destructeur appelé." << std::endl;
    }

    // Méthode pour afficher les détails de la voiture
    void displayDetails() const {
        std::cout << "Modèle : " << model << ", Vitesse : " << speed << " km/h" << std::endl;
    }
};

int main() {
    // Constructeur par défaut
    Car defaultCar;
    defaultCar.displayDetails();

    // Constructeur avec paramètres
    Car customCar("Sedan", 120);
    customCar.displayDetails();

    // Constructeur de copie
    Car copiedCar = customCar;
    copiedCar.displayDetails();

    // Opérateur d'affectation
    Car assignedCar;
    assignedCar = customCar;
    assignedCar.displayDetails();

    // Fin du bloc, destructeur appelé pour chaque objet créé
    return 0;
}

```


# Comparaison des entiers et nombres flottants

L'affirmation selon laquelle "les caractéristiques des entiers et des nombres à virgule flottante sont opposées" peut être expliquée en se basant sur les informations fournies dans les articles. Voici une explication détaillée :

## 1. Exactitude vs. Précision :

- Entiers : Les entiers offrent une exactitude totale. Chaque entier représente une valeur précise et unique sans perte d'information. Les opérations sur les entiers garantissent une correspondance bit à bit avec le résultat correct.
- Nombres à virgule flottante : Ils offrent une bonne précision car ils conservent toutes les informations disponibles pour représenter les nombres. Cependant, leur exactitude est limitée, car certaines fractions ne peuvent pas être représentées de manière exacte en binaire, entraînant des erreurs d'arrondi.

## 2. Représentation interne :

- Entiers : Leur représentation binaire est directe et littérale, avec chaque bit représentant une puissance de 2.
- Nombres à virgule flottante : Leur représentation interne est plus complexe, utilisant une structure composée de signe, exposant et mantisse. Cette complexité permet une plus grande gamme de valeurs, mais introduit des subtilités dans la représentation.

## 3. Comparaisons d'égalité :

- Entiers : Les opérations sur les entiers utilisent l'opérateur "==" de manière fiable pour tester l'égalité bit à bit.
- Nombres à virgule flottante : L'utilisation de "==" pour les nombres à virgule flottante peut être problématique en raison des erreurs d'arrondi. On recommande d'utiliser des tolérances (comme epsilon) pour des comparaisons "proches de l'égalité".

## 4. Débordement :

- Entiers : Le débordement des entiers est détectable, et il se manifeste souvent par un retour au début de la plage de valeurs.
- Nombres à virgule flottante : Les débordements de nombres à virgule flottante peuvent conduire à des valeurs spéciales comme +inf ou -inf, offrant une manière plus prévisible de gérer les situations de débordement.

## 5. Perte de Signification :

- Entiers : Les entiers n'ont pas de problème de perte de signification car chaque valeur entière est représentée exactement.
- Nombres à virgule flottante : La perte de signification peut se produire lors de manipulations où des chiffres significatifs sont perdus, ce qui peut entraîner des résultats imprécis.


### En résumé, alors que les entiers se caractérisent par une exactitude complète et une représentation binaire simple, les nombres à virgule flottante privilégient la précision tout en introduisant des défis liés à l'exactitude et à la manipulation des fractions en binaire. Ces caractéristiques opposées sont mises en évidence dans les articles par les différences fondamentales entre les deux types de données numériques en programmation.


## 6. les nombres a virgules fixes\

article source : https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html

la représentation en virgule fixe comme une alternative aux nombres en virgule flottante pour traiter les nombres réels avec des parties fractionnaires

L'article explique que le décalage d'un motif binaire vers la droite de 1 bit équivaut à diviser le nombre par 2, mettant en évidence le rôle fondamental du décalage dans la représentation en virgule fixe.

Les avantages et les inconvénients de la représentation en virgule fixe sont discutés. Les avantages comprennent des opérations arithmétiques simples et efficaces similaires à celles des entiers, en utilisant le matériel existant. Cependant, l'inconvénient est la plage et la précision limitées par rapport aux représentations en virgule flottante.

L'arithmétique en virgule fixe est présentée comme une méthode simple et puissante pour représenter des nombres fractionnaires, offrant des performances plus rapides dans certaines applications mais nécessitant des compromis en termes de plage et de précision.




