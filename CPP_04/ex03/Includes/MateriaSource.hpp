/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:27 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:28 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
