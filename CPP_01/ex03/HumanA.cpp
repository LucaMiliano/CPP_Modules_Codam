/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:26 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 17:38:19 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon_type) :name(name), weapon_a(weapon_type)
{
	// this->name = name;
	// weapon_a = weapon_type;
	// // weapon_a.setType(weapon_type);
	// // if (weapon_a.getType() == "")
	// // 	weapon_a.setType("random stuff they found on the floor");
}

void HumanA::attack()
{

	std::cout << name << " attacks with their weapon " << weapon_a.getType() << ".\n";
}