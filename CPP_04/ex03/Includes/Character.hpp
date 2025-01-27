/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:07 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:08 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

// //Includes
// #include "ICharacter.hpp"
// #include "Floor.hpp"
// #include "AMateria.hpp"

#include "AMateria.hpp"  // AMateria wird vollständig benötigt
#include "ICharacter.hpp"
#include "Floor.hpp"

//Class

class Character : public ICharacter
{
	private:
		std::string			_characterName;
		AMateria			*inventory[4];
		Floor 				*_SharedFloor;
		// //Floor
		// static AMateria		**_floor;
		// static size_t		_floorSize; // Aktuelle Anzahl der Elemente auf dem Boden
		// static size_t		_floorCapacity; // Aktuelle Kapazität des Arrays
	//OCF
	public:
		Character(Floor* floor);
		Character(std::string InputName, Floor* floor);
		Character(const Character &og);
		Character &operator=(const Character &og);
		~Character();
	//Methodes
	public:
			std::string const & getName() const override;
			void equip(AMateria* m) override;
			void unequip(int idx) override;
			void use(int idx, ICharacter& target) override;
	// //Floor --> Dynamic Array, that can be resized
	// public:
	// 	void resizeFloor(size_t newCapacity);
};

#endif
