/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:16:20 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/08 17:19:46 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap Ferb("Ferb");
	
	Ferb.attack("Phineas");
	Ferb.takeDamage(8);
	Ferb.beRepaired(2);
	Ferb.attack("Phineas");
	Ferb.beRepaired(2);
	Ferb.takeDamage(8);
	Ferb.beRepaired(2);
	Ferb.attack("Phineas");
	Ferb.takeDamage(9);
	return (0);
}