// #include "Dog.hpp"
#include "../Includes/Dog.hpp"

Dog::Dog() : AAnimal(), _brain(new Brain())
{
	setType("Dog");
	std::cout << "[DOG]: Default Constructor called for " << getType() << "\n";
}

Dog::Dog(const Dog &og) : AAnimal(og), _brain(new Brain(*(og._brain)))
{
	*this = og;
	std::cout << "[DOG]: Copy Constructor called for " << getType() << "\n";
}


Dog &Dog::operator=(const Dog &og)
{
	std::cout << "[DOG]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
	{
		this->_m_type = og._m_type;
		this->_brain = og._brain;
	}
	return (*this);
}

Dog::~Dog()
{
	std::cout << "[DOG]: Destructor called for " << getType() << "\n";
	delete _brain;
}

void	Dog::makeSound() const
{
	std::cout << "[DOG]: " << getType() << " makes WUF WUF\n";
}


