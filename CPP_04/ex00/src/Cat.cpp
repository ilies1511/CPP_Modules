#include "Cat.hpp"

Cat::Cat()
{
	setType("Cat");
	std::cout << "CAT Default Constructor called for " << getType() << "\n";
}

Cat::Cat(const Cat &og)
{
	*this = og;
	std::cout << "CAT Copy Constructor called for " << getType() << "\n";
}

Cat &Cat::operator=(const Cat &og)
{
	std::cout << "CAT Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

Cat::~Cat()
{
	std::cout << "CAT Destructor called for " << getType() << "\n";
}

void	Cat::makeSound() const
{
	std::cout << "CAT " << getType() << " makes MIAU MIAU\n";
}
