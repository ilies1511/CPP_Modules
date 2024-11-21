/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:46:05 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:46:06 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP


//Includes
#include <string>
#include <iostream>

//Classes
class Brain
{
	private:
		std::string ideas[100];
	//OCF
	public:
		Brain(void);
		Brain(const Brain &og);
		Brain& operator=(const Brain &og);
		~Brain();
	//Methodes
	public:
		std::string	getIdeas(size_t index) const;
		void		setIdeas(size_t index, std::string InputStr);
};

#endif


