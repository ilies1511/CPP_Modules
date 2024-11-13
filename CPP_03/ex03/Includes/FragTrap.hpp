#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

//Includes
# include "ClapTrap.hpp"
//Classes

class FragTrap : virtual public ClapTrap
{
	//OCF
	public:
		FragTrap();
		explicit FragTrap(std::string InputName);
		FragTrap(const FragTrap &og);
		FragTrap& operator=(const FragTrap &og);
		~FragTrap();
	//Memebers
	public:
		void highFivesGuys(void);
};

#endif
