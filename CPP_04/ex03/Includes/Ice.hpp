#ifndef ICE_HPP
# define ICE_HPP

//Includes
#include "AMateria.hpp"

//Class
class Ice : public AMateria
{
	private:
	//OCF
	public:
		Ice(void);
		Ice(const Ice &og);
		Ice& operator=(const Ice &og);
		~Ice();
	//Methodes
	public:
		AMateria* clone() const override;
		void use(ICharacter& target) override;


};

#endif
