#ifndef WRONG_ANIMAL_CPP
# define WRONG_ANIMAL_CPP

//Includes
#include <iostream>
#include <string>

//Class
class WrongAnimal
{
	protected:
		std::string _m_type;
	//OCF
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(const WrongAnimal &og);
		WrongAnimal& operator=(const WrongAnimal &og);
		virtual ~WrongAnimal();
	//Methodes:
	public:
		virtual void	makeSound() const ;
		//Getter
		std::string		getType(void) const;
		//Setter
		void			setType(std::string name);

};

#endif
