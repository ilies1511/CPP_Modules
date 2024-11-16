#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "[BRAIN]: Default Constructor called\n";
}

//2check if '*this = og' is enough
Brain::Brain(const Brain &og)
{
	std::cout << "[BRAIN]: Copy Constructor called\n";
	// *this = og;
	for (int i; i < 100; i++)
		this->ideas[i] = og.ideas[i];
}

Brain &Brain::operator=(const Brain &og)
{
	std::cout << "[BRAIN]: Copy Assignment operator called for\n";
	if (this != &og)
	{
		for (int i; i < 100; i++)
			this->ideas[i] = og.ideas[i];
	}
	return (*this);
}

Brain::~Brain()
{
	std::cout << "[BRAIN]: Destructor called for\n";
}

//Methodes
std::string	Brain::getIdeas(size_t index) const
{
	return (this->ideas[index]);
}

void	Brain::setIdeas(size_t index, std::string InputStr)
{
	this->ideas[index].assign(InputStr);
}
