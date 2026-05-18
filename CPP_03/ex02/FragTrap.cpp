/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 16:09:57 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/18 16:16:16 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->name = name;
	hit_points = 100;
	energy_points = 100;
	attack_damage = 30;
	std::cout << "This is a constructed FragTrap, not a ScavTrap\n";
}

FragTrap::FragTrap(const FragTrap& other)
	: ClapTrap(other)
{
	name = other.name;
	hit_points = other.hit_points;
	energy_points = other.energy_points;
	attack_damage = other.attack_damage;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
	if (this != &other)
	{
		name = other.name;
		hit_points = other.hit_points;
		energy_points = other.energy_points;
		attack_damage = other.attack_damage;
	}
	return (*this);
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " is requesting super positive a high five!\n";
}

FragTrap::~FragTrap()
{
	std::cout << name << " is deconstructed as FragTrap\n";
}