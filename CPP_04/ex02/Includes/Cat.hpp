#ifndef CAT_HPP
# define CAT_HPP

//Includes
#include "AAnimal.hpp"
#include "Brain.hpp"

//Class
class Cat : public AAnimal
{
	private:
		Brain	*_brain;
	//OCF
	public:
		//Default Constructor
		Cat();
		//Default Name Constructor
		// Cat(std::string name);
		//Copy Constructor
		Cat(const Cat &og);
		Cat& operator=(const Cat &og);
		~Cat();
	//Methodes
	public:
		void	makeSound() const override;
};

#endif
