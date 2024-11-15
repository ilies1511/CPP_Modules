#include "Dog.hpp"

Dog::Dog()
{
	setType("Dog");
	std::cout << "[DOG]: Default Constructor called for " << getType() << "\n";
}

Dog::Dog(const Dog &og)
{
	*this = og;
	std::cout << "[DOG]: Copy Constructor called for " << getType() << "\n";
}


Dog &Dog::operator=(const Dog &og)
{
	std::cout << "[DOG]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[DOG]: Destructor called for " << getType() << "\n";
}

void	Dog::makeSound() const
{
	std::cout << "[DOG]: " << getType() << " makes WUF WUF\n";
}


