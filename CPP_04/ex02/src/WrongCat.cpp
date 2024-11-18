#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	setType("WrongCat");
	std::cout << "[WRONGCAT]: Default Constructor called for " << getType() << "\n";
}

WrongCat::WrongCat(const WrongCat &og) : WrongAnimal(og)
{
	*this = og;
	std::cout << "[WRONGCAT]: Copy Constructor called for " << getType() << "\n";
}

WrongCat &WrongCat::operator=(const WrongCat &og)
{
	std::cout << "[WRONGCAT]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "[WRONGCAT]: Destructor called for " << getType() << "\n";
}

void	WrongCat::makeSound() const
{
	std::cout << "[WRONGCAT]: " << getType() << " makes WMIAU WMIAU\n";
}