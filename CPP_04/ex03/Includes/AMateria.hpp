/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:04 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:05 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

//Inclues
#include <iostream>
#include <ICharacter.hpp>

class AMateria
{
	protected:
		std::string _type; //Either ice or cure
	//OCF
	public:
		AMateria(void);
		AMateria(std::string const & type);
		AMateria(const AMateria &og);
		AMateria& operator=(const AMateria &og);
		virtual ~AMateria();
	//Methodes
	public:
		std::string const & getType() const; //Returns the materia type
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);
	};

#endif
