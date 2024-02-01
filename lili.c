je voudrais pouvoir creer le zombie de la stack directement avec randomChump()


int main()
{

	// creation d'un zombie dans la stack (la pile)
	randomChump("GagaStack");

	// creation d'un zombie dans la heap (le tas)
	// et liberation de la memoire allouee a travers la fonction newZombie
	Zombie* myZombiePtr = myZombie.newZombie("BibiHeap");
	myZombiePtr->announce();
	delete myZombiePtr;

	return 0;
}
void	Zombie::randomChump(std::string name) {

	Zombie createZombie(name);
	createZombie.announce();

	return ;
}


main.cpp: In function ‘int main()’:
main.cpp:22:9: error: ‘randomChump’ was not declared in this scope
   22 |         randomChump("GagaStack");
      |         ^~~~~~~~~~~
make: *** [Makefile:32: objs/main.o] Error 1