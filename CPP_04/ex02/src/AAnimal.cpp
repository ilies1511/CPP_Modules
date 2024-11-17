#include "AAnimal.hpp"

//Default Constructor
AAnimal::AAnimal() : _m_type("AAnimal")
{
	std::cout << "[AANIMAL]: Default Constructor called for " << getType() << "\n";
	// std::cout << "[AANIMAL]: Default Constructor called\n";
}

//Default Name Constructor
AAnimal::AAnimal(std::string InputType) : _m_type(InputType)
{
	std::cout << "[AANIMAL]: NameDefault Constructor called for " << getType() << "\n";
	// std::cout << "[AANIMAL]: Default Constructor called for " << _m_type << "\n";
	// std::cout << "[AANIMAL]: NameDefault Constructor called\n";
}

//Copy Constructor
AAnimal::AAnimal(const AAnimal &og) : _m_type(og._m_type)
{
	std::cout << "[AANIMAL]: Copy Constructor called for " << getType() << "\n";
	*this = og;
}

//Copy Assigment Constructor
AAnimal &AAnimal::operator=(const AAnimal &og)
{
	std::cout << "[AANIMAL]: Copy Assignment operator called for " << getType() << "\n";
	if (this != &og)
		this->_m_type = og._m_type;
	return (*this);
}

//Destructor
AAnimal::~AAnimal()
{
	std::cout << "[AANIMAL]: Destructor called for " << getType() << "\n";
}

//Getter: Type
std::string	AAnimal::getType(void) const
{
	return (this->_m_type);
}

void	AAnimal::setType(std::string name)
{
	this->_m_type = name;
}

