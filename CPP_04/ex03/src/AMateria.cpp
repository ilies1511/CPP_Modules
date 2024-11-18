#include "AMateria.hpp"

AMateria::AMateria(void) : _type("DefaultMateria")
{
	std::cout << "[AMateria]: Default Constructor called\n";
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	std::cout << "[AMateria]: Default Name Constructor called\n";
}

AMateria::AMateria(const AMateria &og)
{
	std::cout << "[AMateria]: Copy Constructor called\n";
	this->_type = og._type;
}

AMateria &AMateria::operator=(const AMateria &og)
{
	std::cout << "[AMateria]: Copy Assigmen Constructor called\n";
	(void)og;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "[AMateria]: Destructor called\n";
}

//Getter
std::string const & AMateria::getType() const
{
	return (this->_type);
}
