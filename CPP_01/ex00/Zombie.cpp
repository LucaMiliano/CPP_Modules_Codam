/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:05:15 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 16:21:23 by lpieck           ###   ########.fr       */
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