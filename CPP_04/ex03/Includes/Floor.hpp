/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Floor.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:13 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:15 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOR_HPP
# define FLOOR_HPP

//Includes
#include "AMateria.hpp"

//Class
class Floor
{
	private:
		AMateria	**_floor;
		size_t		_floorSize; // Aktuelle Anzahl der Elemente auf dem Boden
		size_t		_floorCapacity; // Aktuelle Kapazität des Arrays

		void resizeFloor(size_t newCapacity);
	//OCF
	public:
		Floor();
		Floor(const Floor &og);
		Floor &operator=(const Floor &og);
		~Floor();
	//Methodes
	public:
		void	addMateria(AMateria *newM);
		//getter
		size_t	getFloorSize(void) const;
		size_t	getFloorCapacity(void) const;
		AMateria *getMateria(size_t index) const;
};

#endif
