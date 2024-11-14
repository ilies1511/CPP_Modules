/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:46:28 by iziane            #+#    #+#             */
/*   Updated: 2024/11/14 16:46:29 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The "using" keyword allows DiamondTrap to explicitly bring
	the attack method from ScavTrap into the class. This is necessary
	because DiamondTrap inherits from both ScavTrap and FragTrap,
	which both define their own attack methods. Without "using",
	the compiler would not know which attack method to call, causing
	ambiguity. By using "using ScavTrap::attack;", we specify that
	DiamondTrap should use the attack method from ScavTrap.
*/

#ifndef DIAMOND_TRAP_HPP
# define DIAMOND_TRAP_HPP

//Includes
#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

//Class
class DiamondTrap :  public ScavTrap, public FragTrap
{
	private:
		std::string mDiamondTrap_name; // own Name for DiamondTrap Instance
	//OCF
	public:
		DiamondTrap(void);
		DiamondTrap(std::string InputName);
		DiamondTrap(const DiamondTrap &og);
		DiamondTrap &operator=(const DiamondTrap &og);
		~DiamondTrap(void);
	public:
		void whoAmI();
		using ScavTrap::attack;
		// void	attack(const std::string& target);
};

#endif
