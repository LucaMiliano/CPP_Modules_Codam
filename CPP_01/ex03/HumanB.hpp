/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:31 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 18:33:40 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B
#define HUMAN_B
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanB{
	public:
		std::string name;
		Weapon* weapon_b;
		void attack();

		HumanB(const std::string& name);
		void setWeapon(Weapon& weapon_type);
};

#endif