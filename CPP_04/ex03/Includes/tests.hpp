/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iziane <iziane@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 09:49:33 by iziane            #+#    #+#             */
/*   Updated: 2024/11/21 09:49:34 by iziane           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_HPP
# define TESTS_HPP

//Includes
#include "MateriaSource.hpp"
#include "AMateria.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "printer.hpp"

namespace testrunner
{
	void	subj();
	void	cwazy(void);
	void	unequipEdgeCases(void);
	void	floorOverflowTest(void);
	void	useMultipleTargets(void);
	void	integratedMateriaSourceTest(void);

}

#endif
