#ifndef CURE_HPP
# define CURE_HPP

//Includes
#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
	private:
	//OCF
	public:
		Cure(void);
		Cure(const Cure &og);
		Cure &operator=(const Cure &og);
		~Cure();
	public:
		AMateria* clone() const override;
		void use(ICharacter& target) override;
};

#endif
