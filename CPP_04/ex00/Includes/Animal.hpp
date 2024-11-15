#ifndef ANIMAL_CPP
# define ANIMAL_CPP

//Includes
#include <iostream>
#include <string>

//Class
class Animal
{
	protected:
		std::string type;
	//OCF
	public:
		//Default Constructor
		Animal();
		//Default Name Constructor
		Animal(std::string type);
		//Copy Constructor
		Animal(const Animal &og);
		//Copy Assigment Constructor
		Animal& operator=(const Animal &og);
		virtual ~Animal();
	//Methodes:
	public:
		virtual void	makeSound();
};

#endif
