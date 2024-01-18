Sans resoudre l exercice, peux tu me dire les etapes a suivre pour resoudre cette exercice. Je ne veux pas que tu fasses l exercice. Je veux juste que tu m explique les notions et les etapes importantes

My Awesome PhoneBook
Dossier de rendu : ex01/
Fichiers à rendre : Makefile, *.cpp, *.{h, hpp}
Fonctions interdites : Aucune
Bienvenue dans les années 80 et leur incroyable technologie ! Concevez un programme
qui se comporte comme un répertoire pas si incroyable que ça.
Vous devez implémenter deux classes :
•PhoneBook
◦Représente le répertoire.
◦Contient un tableau de contacts.
◦Peut enregistrer 8 contacts maximum. Si l’utilisateur tente d’ajouter un 9ème
contact, remplacez le plus ancien par celui-ci.
◦Notez que l’allocation dynamique est interdite.
•Contact
◦Représente un contact dans le répertoire.
Dans votre code, l’objet répertoire doit être une instance de la classe PhoneBook.
Même chose pour les objets contacts, qui doivent être chacun une instance de la classe
Contact. Vous êtes libre de concevoir vos classes comme vous le sentez. Par contre, ayez
en tête que ce qui est toujours utilisé dans une classe est privé, et que ce qui peut l’être
en dehors est public.

Au lancement du programme, le répertoire est vide et l’utilisateur peut entrer une
commande. Le programme accepte les entrées suivantes : ADD, SEARCH et EXIT.
•ADD : enregistrer un nouveau contact
◦Si l’utilisateur entre cette commande, le programme lui demande de remplir
une par une les informations du nouveau contact. Une fois tous les champs
complétés, le nouveau contact est ajouté au répertoire.
◦Un contact possède les champs suivants : first name (prénom), last name
(nom de famille), nickname (surnom), phone number (numéro de téléphone),
et darkest secret (son plus lourd secret). Les champs d’un contact enregistré ne
peuvent être vides.
•SEARCH : affiche le contact demandé
◦Affiche les contacts enregistrés sous la forme d’une liste de 4 colonnes : index,
first name, last name et nickname.
◦Chaque colonne doit faire 10 caractères de long. Elles doivent être séparées
par un pipe (’|’). Leur texte est aligné à droite. Si le texte dépasse la largeur
de la colonne, il faut le tronquer et remplacer le dernier caractère affiché par
un point (’.’).
◦Ensuite, le programme demande à l’utilisateur d’entrer l’index du contact à af-
ficher. Si l’index ou son format sont incorrects, gérez cela de manière pertinente.
Sinon, affichez les informations du contact, une par ligne.
•EXIT
◦Le programme quitte et les contacts sont perdus à jamais !
•Toute autre entrée est ignorée.
Une fois la commande correctement exécutée, le programme attend à nouveau une
entrée. Il prend fin lorsque l’utilisateur entre EXIT