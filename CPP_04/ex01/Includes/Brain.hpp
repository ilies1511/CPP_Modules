#ifndef BRAIN_HPP
# define BRAIN_HPP


//Includes
#include "Animal.hpp"

//Classes
class Brain
{
	private:
		std::string ideas[100];
	//OCF
	public:
		Brain(void);
		Brain(const Brain &og);
		Brain& operator=(const Brain &og);
		~Brain();
	//Methodes
	public:
		std::string	getIdeas(size_t index) const;
		void		setIdeas(size_t index, std::string InputStr);
};

#endif


