/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:45:23 by iziane            #+#    #+#             */
/*   Updated: 2024/11/14 16:45:25 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	explicit prevents implicit conversion from std::string to ScavTrap,
	ensuring ScavTrap can only be constructed with a string explicitly.
*/

#ifndef SCAV_TRAP_HPP
# define SCAV_TRAP_HPP

//Includes
# include "ClapTrap.hpp"
//Classes

class ScavTrap : public ClapTrap
{
	//OCF
	public:
		ScavTrap();
		explicit ScavTrap(std::string InputName);
		ScavTrap(const ScavTrap &og);
		ScavTrap& operator=(const ScavTrap &og);
		~ScavTrap();
	//Memebers
	public:
		void attack(const std::string& target) override; // override spezifiziert, dass wir die Methode überschreiben
		void guardGate(); // spezielle Methode für den Gatekeeper-Modus
};

#endif
