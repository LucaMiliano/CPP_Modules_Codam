/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:38 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 18:31:12 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string weapon_type)
{
	setType(weapon_type);
}

const std::string& Weapon::getType() const
{
	return type;
}

void Weapon::setType(const std::string& newType)
{
	type = newType;
	return ;
}