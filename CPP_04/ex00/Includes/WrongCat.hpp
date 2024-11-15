#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

//Includes
#include "WrongAnimal.hpp"

//Class
class WrongCat : public WrongAnimal
{
	//OCF
	public:
		WrongCat();
		WrongCat(std::string name);
		WrongCat(const WrongCat &og);
		WrongCat operator=(const WrongCat &og);
		~WrongCat();
	//Methodes
	public:
		void	makeSound() override;
};

#endif
