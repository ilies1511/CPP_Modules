#include "AMateria.hpp"
#include "printer.hpp"

AMateria::AMateria(void) : _type("DefaultMateria")
{
	std::cout << "[AMateria]: Default Constructor called\n";
	printer::ocf_printer("AMateria", printer::OCF_TYPE::DC, OLIVE);
}

AMateria::AMateria(std::string const & type) : _type(type)
{
	// std::cout << "[AMateria]: Default Name Constructor called\n";
	printer::ocf_printer("AMateria", printer::OCF_TYPE::DNC, OLIVE);
}

AMateria::AMateria(const AMateria &og)
{
	// std::cout << "[AMateria]: Copy Constructor called\n";
	printer::ocf_printer("AMateria", printer::OCF_TYPE::CC, OLIVE);

	this->_type = og._type;
}

AMateria &AMateria::operator=(const AMateria &og)
{
	// std::cout << "[AMateria]: Copy Assigmen Constructor called\n";
	printer::ocf_printer("AMateria", printer::OCF_TYPE::CAC, OLIVE);
	(void)og;
	return (*this);
}

AMateria::~AMateria()
{
	printer::ocf_printer("AMateria", printer::OCF_TYPE::D, OLIVE);
	// std::cout << "[AMateria]: Destructor called\n";
}

//TODO:
void AMateria::use(ICharacter& target)
{
	std::cout << target.getName() << " kassiert eine osmanische Schelle\n";
}

//Getter
std::string const & AMateria::getType() const
{
	return (this->_type);
}
