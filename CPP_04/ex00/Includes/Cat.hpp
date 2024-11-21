/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:09 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:10 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

//Includes
#include "Animal.hpp"

//Class
class Cat : public Animal
{
	private:

	//OCF
	public:
		//Default Constructor
		Cat();
		//Default Name Constructor
		// Cat(std::string name);
		//Copy Constructor
		Cat(const Cat &og);
		Cat& operator=(const Cat &og);
		~Cat();
	//Methodes
	public:
		void	makeSound() const override;
};

#endif
