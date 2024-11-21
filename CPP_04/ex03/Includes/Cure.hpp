/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:11 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:12 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
