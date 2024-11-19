#include "Cure.hpp"

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	std::cout << "[CURE]: Default Constructor called\n";
}

Cure::Cure(const Cure &og)
{
	std::cout << "[CURE]: Copy Constructor called\n";
	this->_type = og._type;
}

Cure &Cure::operator=(const Cure &og)
{
	std::cout << "[CURE]: Copy Assigment Constructor called\n";
	(void)og;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "[CURE]: Destructor called\n";
}

//Members
AMateria* Cure::clone() const
{
	return(new Cure(*this));
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

