/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:46:00 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:46:02 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CPP
# define ANIMAL_CPP

//Includes
#include <iostream>
#include <string>

//Class
class Animal
{
	protected:
		std::string _m_type;
	//OCF
	public:
		//Default Constructor
		Animal();
		//Default Name Constructor
		Animal(std::string InputType);
		//Copy Constructor
		Animal(const Animal &og);
		//Copy Assigment Constructor
		Animal& operator=(const Animal &og);
		//Destructor
		virtual ~Animal();
	//Methodes:
	public:
		virtual void	makeSound(void) const;
		//Getter
		std::string		getType(void) const;
		//Setter
		void			setType(std::string name);
};

#endif
