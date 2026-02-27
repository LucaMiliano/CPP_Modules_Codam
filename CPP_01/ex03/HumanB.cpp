/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:21 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 18:29:16 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(const std::string& name) : name(name), weapon_b(nullptr)
{
	// HumanB::weapon_b.setType("");
}

void HumanB::setWeapon(Weapon& weapon_type)
{
	weapon_b = &weapon_type;
}

void HumanB::attack()
{
	if (weapon_b == nullptr)
		std::cout << name << " is unarmed...\n";
	else
		std::cout << name << " attacks with their weapon " << weapon_b->getType() << ".\n";
}
