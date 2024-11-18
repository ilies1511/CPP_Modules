#include "Ice.hpp"

//OCF - Begin
Ice::Ice(void) : AMateria()
{
	std::cout << "[ICE]: Default Constructor called\n";
}

Ice::Ice(const Ice &og) : AMateria(og)
{
	std::cout << "[ICE]: Copy Constructor called\n";
	this->_type = og._type;
}

Ice& Ice::operator=(const Ice &og)
{
	std::cout << "[ICE]: Copy Assigment Constructor called\n";
	(void)og;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "[ICE]: Destructor called\n";
}
//OCF - END

//Methodes
AMateria* Ice::clone() const
{
	return(new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*\n";
}
