/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:47:30 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:47:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

//Includes
#include "AAnimal.hpp"
#include "Brain.hpp"

//Class
class Dog : public AAnimal
{
	private:
		Brain* _brain;
	//OCF
	public:
		Dog();
		// Dog(std::string name);
		Dog(const Dog &og);
		Dog& operator=(const Dog &og);
		~Dog();
	//Methodes
	public:
		void	makeSound() const override;
		Brain*	getBrain() const;

};

#endif
