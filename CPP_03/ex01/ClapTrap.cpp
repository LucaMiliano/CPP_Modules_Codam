/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:16:23 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/08 17:18:25 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
	this->hit_points = 10;
	this->energy_points = 10;
	this->attack_damage = 0;
	std::cout << name << " is constructed as ClapTrap\n";
}

ClapTrap::~ClapTrap()
{
	std::cout << name << " is deconstructed as ClapTrap\n";
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	this->name = other.name;
	this->attack_damage = other.attack_damage;
	this->energy_points = other.energy_points;
	this->hit_points = other.hit_points;
}
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->attack_damage = other.attack_damage;
		this->energy_points = other.energy_points;
		this->hit_points = other.hit_points;
	}
	return(*this);
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead and can't attack anymore.\n";
		return ;
	}
	else if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to attack " << target << ".\n";
		return ;
	}
	else
	{
		std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!\n";
		energy_points--;
	}
	return ;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int dmg = 0;
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is already dead (R.I.P.).\n";
		return ;
	}
	else
	{
		while (hit_points > 0 && dmg < amount)
		{
			dmg++;
			hit_points--;
		}
		std::cout << "ClapTrap " << name << " took " << dmg << " damage, leaving " << hit_points << " points of health!\n";
	}
	if (hit_points <= 0)
		std::cout << "ClapTrap " << name << " died...\n";
	return ;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_points <= 0)
	{
		std::cout << "ClapTrap " << name << " is dead and can't repair itself anymore.\n";
		return ;
	}
	if (energy_points <= 0)
	{
		std::cout << "ClapTrap " << name << " has no energy left to repair itself.\n";
		return ;
	}
	hit_points = hit_points + amount;
	energy_points--;
	std::cout << "ClapTrap " << name << " repaired for " << amount << " health points, now having " << hit_points << " points of health!\n";
	return ;
};
