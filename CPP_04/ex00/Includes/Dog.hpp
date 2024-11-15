#ifndef DOG_HPP
# define DOG_HPP

//Includes
#include "Animal.hpp"

//Class
class Dog : public Animal
{
	private:

	//OCF
	public:
		Dog();
		// Dog(std::string name);
		Dog(const Dog &og);
		Dog& operator=(const Dog &og);
		~Dog();
	//Methodes
	public:
		void	makeSound() const override;
};

#endif
