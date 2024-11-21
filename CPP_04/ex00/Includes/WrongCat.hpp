/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:45:22 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:45:24 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

//Includes
#include "WrongAnimal.hpp"

//Class
class WrongCat : public WrongAnimal
{
	//OCF
	public:
		WrongCat();
		// WrongCat(std::string name);
		WrongCat(const WrongCat &og);
		WrongCat& operator=(const WrongCat &og);
		~WrongCat();
	//Methodes
	public:
		void	makeSound() const;
};

#endif
