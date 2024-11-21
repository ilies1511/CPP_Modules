#ifndef DOG_HPP
# define DOG_HPP

//Includes
#include "AAnimal.hpp"
#include "Brain.hpp"

//Class
class Dog : public AAnimal
{
	private:
		Brain* _brain;
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
		Brain*	getBrain() const;

};

#endif
