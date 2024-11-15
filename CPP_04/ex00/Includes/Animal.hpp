#ifndef ANIMAL_CPP
# define ANIMAL_CPP

//Includes
#include <iostream>
#include <string>

//Class
class Animal
{
	protected:
		std::string _m_type;
	//OCF
	public:
		//Default Constructor
		Animal();
		//Default Name Constructor
		Animal(std::string InputType);
		//Copy Constructor
		Animal(const Animal &og);
		//Copy Assigment Constructor
		Animal& operator=(const Animal &og);
		//Destructor
		virtual ~Animal();
	//Methodes:
	public:
		virtual void	makeSound(void) const;
		//Getter/Setter
		std::string		getType(void) const;
};

#endif
