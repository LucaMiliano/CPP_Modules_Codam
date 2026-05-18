/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:16:20 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/18 16:13:49 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap Ferb("Ferb");
	
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
	return (0);
}