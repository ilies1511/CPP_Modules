#include "Cat.hpp"

Cat::Cat() : Animal(), _brain(new Brain())
{
	setType("Cat");
	std::cout << "[CAT]: Default Constructor called for " << getType() << "\n";
}

Cat::Cat(const Cat &og) : Animal(og), _brain(new Brain(*(og._brain)))
{
	*this = og;
	std::cout << "[CAT]: Copy Constructor called for " << getType() << "\n";
}

Cat &Cat::operator=(const Cat &og)
{
	std::cout << "[CAT]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
	{
		Animal::operator=(og);
		if(_brain)
			delete _brain;
		_brain = new Brain(*og._brain);
	}
	return (*this);
}

Cat::~Cat()
{
	std::cout << "[CAT]: Destructor called for " << getType() << "\n";
	delete _brain;
}

Brain* Cat::getBrain() const
{
	return (_brain);
}

void	Cat::makeSound() const
{
	std::cout << "[CAT]: " << getType() << " makes MIAU MIAU\n";
}
