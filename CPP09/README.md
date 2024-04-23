# Exercice 00: Bitcoin Exchange

**Objectif** : Créer un programme qui calcule la valeur de bitcoins à une date donnée en utilisant des données provenant de fichiers CSV.

**Contraintes spécifiques** : Utilisation d'au moins un conteneur pour stocker et manipuler les données des fichiers CSV.

**Conteneur suggéré** : `std::map` pour stocker les paires date-valeur du bitcoin. Ces conteneurs permettent une recherche rapide des dates et la mise à jour des valeurs correspondantes.

---

# Exercice 01: Reverse Polish Notation (RPN)

**Objectif** : Évaluer des expressions mathématiques écrites en notation polonaise inversée.

**Contraintes spécifiques** : Utilisation d'au moins un conteneur pour gérer les opérations et les nombres.

**Conteneur suggéré** : `std::stack` semble être le choix le plus naturel pour ce type de problème, car il s'agit d'évaluer des expressions en notation polonaise inversée, où une structure de données LIFO (Last In, First Out) est idéale.

---

# Exercice 02: PmergeMe

**Objectif** : Trier une séquence de nombres en utilisant l'algorithme de tri "merge-insert".

**Contraintes spécifiques** : Utilisation de deux conteneurs pour implémenter l'algorithme de tri.

**Conteneurs suggérés** :
- Premier conteneur : `std::vector` pour stocker la séquence de nombres. Les vecteurs sont bons pour stocker et accéder à de grandes séquences de données et travailler avec l'algorithme de tri.
- Deuxième conteneur : `std::list` pour la deuxième implémentation de l'algorithme de tri, car les listes sont efficaces pour les opérations d'insertion et de suppression qui peuvent être fréquentes dans un algorithme de tri par fusion.

---

En résumé :

- Exercice 00 : `std::map`
- Exercice 01 : `std::stack`
- Exercice 02 : `std::vector` et `std::list`
