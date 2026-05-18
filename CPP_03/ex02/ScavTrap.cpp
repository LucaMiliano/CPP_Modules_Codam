/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 16:53:06 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/18 16:15:54 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	hit_points = 100;
	energy_points = 50;
	attack_damage = 20;
	std::cout << "This is a constructed ScavTrap...\n";
}

ScavTrap::ScavTrap(const ScavTrap& other)
	: ClapTrap(other)
{
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
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

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is guarding the gate.\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
	{
		std::cout << "ScavTrap " << name << " is dead and can't attack anymore.\n";
		return ;
	}
	else if (energy_points <= 0)
	{
		std::cout << "ScavTrap " << name << " has no energy left to attack " << target << ".\n";
		return ;
	}
	else
	{
		std::cout << "ScavTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
		energy_points--;
	}
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "This is a deconstructed ScavTrap\n";
}