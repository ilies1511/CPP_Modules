/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:17 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:19 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
