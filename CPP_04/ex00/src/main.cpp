
#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

/*
	Leaks Check:
		dorker valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./ex00.out
*/

int main(void)
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	delete meta;
	delete j;
	delete i;
	// // //And more own tests
	// // std::cout << "Alo\n";

	// // // Animal hayuan;
	// // Animal hayuan2("Musti");

	// // // hayuan.makeSound();
	// // // hayuan2.makeS.ound();

	// Cat	cat;
	// cat.makeSound();

	// std::cout << "\n";
	// Dog dog;
	// dog.makeSound();

	return (0);
}
