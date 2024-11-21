/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:47:27 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:47:28 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

//Includes
#include "AAnimal.hpp"
#include "Brain.hpp"

//Class
class Cat : public AAnimal
{
	private:
		Brain	*_brain;
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
		Brain*	getBrain() const;

};

#endif
