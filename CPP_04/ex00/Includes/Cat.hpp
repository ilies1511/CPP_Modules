#ifndef CAT_HPP
# define CAT_HPP

//Includes
#include "Animal.hpp"

//Class
class Cat : public Animal
{
	private:

	//OCF
	public:
		//Default Constructor
		Cat();
		//Default Name Constructor
		Cat(std::string name);
		//Copy Constructor
		Cat(const Cat &og);
		Cat& operator=(const Cat &og);
		~Cat();
	//Methodes
	public:
		void	makeSound() override;
};

#endif
