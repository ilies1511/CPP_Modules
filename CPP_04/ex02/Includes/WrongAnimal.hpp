/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:47:34 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:47:36 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_ANIMAL_CPP
# define WRONG_ANIMAL_CPP

//Includes
#include <iostream>
#include <string>

//Class
class WrongAnimal
{
	protected:
		std::string _m_type;
	//OCF
	public:
		WrongAnimal();
		WrongAnimal(std::string name);
		WrongAnimal(const WrongAnimal &og);
		WrongAnimal& operator=(const WrongAnimal &og);
		virtual ~WrongAnimal();
	//Methodes:
	public:
		void	makeSound() const ;
		//Getter
		std::string		getType(void) const;
		//Setter
		void			setType(std::string name);

};

#endif
