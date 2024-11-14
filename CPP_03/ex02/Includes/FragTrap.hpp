/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:55 by iziane            #+#    #+#             */
/*   Updated: 2024/11/14 16:45:56 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

//Includes
# include "ClapTrap.hpp"
//Classes

class FragTrap : public ClapTrap
{
	//OCF
	public:
		FragTrap();
		explicit FragTrap(std::string InputName);
		FragTrap(const FragTrap &og);
		FragTrap& operator=(const FragTrap &og);
		~FragTrap();
	//Memebers
	public:
		void highFivesGuys(void);
};

#endif
