/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:25:08 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 17:05:22 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{

}

void Zombie::announce(void)
{
	std::cout << name << ": BraiiiiiiinnnzzzZ...\n";
	return ;
}

void Zombie::name_zombie(std::string name)
{
	this->name = name;
	return ;
}

Zombie::~Zombie()
{
	std::cout << name << " died.\n";
}