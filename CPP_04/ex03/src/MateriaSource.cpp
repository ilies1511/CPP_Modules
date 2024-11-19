// #include "../Includes/MateriaSource.hpp"
#include "MateriaSource.hpp"

MateriaSource::MateriaSource(void)
{
	std::cout << "[MATERIASOURCE]: Default Construcor called\n";
	for (size_t i = 0; i < 4; i++)
		this->_MateriaSource_inventory[i] = nullptr;
}

MateriaSource::MateriaSource(const MateriaSource &og)
{
	std::cout << "[MATERIASOURCE]: Copy Construcor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		this->_MateriaSource_inventory[i] = nullptr;
		this->_MateriaSource_inventory[i] = og._MateriaSource_inventory[i];
	}
	*this = og;
}

MateriaSource &MateriaSource::operator=(const MateriaSource &og)
{
	std::cout << "[MATERIASOURCE]: Copy Assignment Construcor called\n";
	if (this != &og)
	{
		for (size_t i = 0; i < 4; ++i)
		{
			if (this->_MateriaSource_inventory[i])
				delete (this->_MateriaSource_inventory[i]);
			if (og._MateriaSource_inventory[i])
				this->_MateriaSource_inventory[i] = og._MateriaSource_inventory[i];
			else
				this->_MateriaSource_inventory[i] = nullptr;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource(void)
{
	std::cout << "[MATERIASOURCE]: Destrucor called\n";
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_MateriaSource_inventory[i])
			delete (this->_MateriaSource_inventory[i]);
	}
}

void MateriaSource::learnMateria(AMateria *og)
{
	if (og == nullptr)
		return ;
	for (size_t i = 0; i < 4; i++)
	{
		if ((this->_MateriaSource_inventory[i]) == nullptr)
		{
			this->_MateriaSource_inventory[i] = og; //Is this enough or do I have to make a Copy of AMAteria og and use this instead ?
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	for (size_t i = 0; i < 4; i++)
	{
		if (this->_MateriaSource_inventory[i] \
			&& (this->_MateriaSource_inventory[i]->getType()) == type)
			return (this->_MateriaSource_inventory[i]->clone());
	}
	std::cout << "[CREATEMATERIA]: ERROR, unknown type\n";
}
