/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:16:23 by lpieck            #+#    #+#             */
/*   Updated: 2026/04/06 13:24:22 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damge = 0;
}

ClapTrap::~ClapTrap()
{
}

void ClapTrap::attack(const std::string& target)
{
	
}
void ClapTrap::takeDamage(unsigned int amount);
void ClapTrap::beRepaired(unsigned int amount);