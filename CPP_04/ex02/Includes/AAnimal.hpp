#ifndef AANIMAL_CPP
# define AANIMAL_CPP

//Includes
#include <iostream>
#include <string>

//Class
class AAnimal
{
	protected:
		std::string _m_type;
	//OCF
	public:
		//Default Constructor
		AAnimal();
		//Default Name Constructor
		AAnimal(std::string InputType);
		//Copy Constructor
		AAnimal(const AAnimal &og);
		//Copy Assigment Constructor
		AAnimal& operator=(const AAnimal &og);
		//Destructor
		virtual ~AAnimal();
	//Methodes:
	public:
		virtual void	makeSound(void) const = 0; // with '= 0' its now an abstract class --> abstract classes has at least one 'pure virtual function'
		//Getter
		std::string		getType(void) const;
		//Setter
		void			setType(std::string name);
};

#endif
