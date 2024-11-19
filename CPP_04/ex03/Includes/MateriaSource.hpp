#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

//Includes
#include "IMateriaSource.hpp"

//Class
class MateriaSource : public IMateriaSource
{
	private:
		AMateria	*_MateriaSource_inventory[4];
	//OCF
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &og);
		MateriaSource &operator=(const MateriaSource &og);
		~MateriaSource(void);
	//Methodes
	public:
		void learnMateria(AMateria*) override;
		AMateria* createMateria(std::string const & type) override;
};

#endif
