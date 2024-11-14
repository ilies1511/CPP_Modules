/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:46:30 by iziane            #+#    #+#             */
/*   Updated: 2024/11/14 16:46:32 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The 'virtual' keyword in the context of inheritance allows for dynamic binding,
	enabling polymorphism. When a class is inherited virtually, like ScavTrap
	inheriting from ClapTrap, it ensures that only one instance of the base class
	(ClapTrap) is shared between derived classes (ScavTrap, FragTrap) in case
	of multiple inheritance. This prevents ambiguity and potential duplication of
	data members from ClapTrap, which could otherwise occur with non-virtual inheritance.

	In addition, the 'virtual' keyword applied to the destructor ensures that the
	correct destructor is called when deleting an object through a base class pointer,
	preventing resource leaks. When a derived class overrides a method (like 'attack'),
	the 'virtual' keyword ensures that the derived version is called at runtime,
	even when the object is referred to by a base class pointer or reference.
*/

#ifndef FRAG_TRAP_HPP
# define FRAG_TRAP_HPP

//Includes
# include "ClapTrap.hpp"
//Classes

class FragTrap : virtual public ClapTrap
{
	//OCF
	public:
		FragTrap();
		explicit FragTrap(std::string InputName);
		FragTrap(const FragTrap &og);
		FragTrap& operator=(const FragTrap &og);
		virtual ~FragTrap();
	//Memebers
	public:
		void highFivesGuys(void);
};

#endif
