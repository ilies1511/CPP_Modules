#include "Cure.hpp"
#include "printer.hpp"

Cure::Cure() : AMateria("cure") //TODO: check if correct
{
	this->_type = "cure";
	// std::cout << "[CURE]: Default Constructor called\n";
	printer::ocf_printer("Cure", printer::OCF_TYPE::DC, LIGHT_RED);
}

Cure::Cure(const Cure &og) : AMateria(og)
{
	// std::cout << "[CURE]: Copy Constructor called\n";
	printer::ocf_printer("Cure", printer::OCF_TYPE::CC, LIGHT_RED);
	this->_type = og._type;
}

Cure &Cure::operator=(const Cure &og)
{
	printer::ocf_printer("Cure", printer::OCF_TYPE::CAC, LIGHT_RED);
	// std::cout << "[CURE]: Copy Assigment Constructor called\n";
	(void)og;
	return (*this);
}

Cure::~Cure()
{
	printer::ocf_printer("Cure", printer::OCF_TYPE::D, LIGHT_RED);
	// std::cout << "[CURE]: Destructor called\n";
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

