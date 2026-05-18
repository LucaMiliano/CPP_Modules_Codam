/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:16:20 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/18 16:39:20 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap Ferb("Ferb");
	
	Ferb.attack("Phineas");
	Ferb.takeDamage(8);
	Ferb.beRepaired(2);
	Ferb.attack("Phineas");
	Ferb.beRepaired(2);
	Ferb.takeDamage(8);
	Ferb.beRepaired(2);
	Ferb.attack("Phineas");
	Ferb.takeDamage(9);
	Ferb.highFivesGuys();
	Ferb.guardGate();
	Ferb.whoAmI();
	return (0);
}