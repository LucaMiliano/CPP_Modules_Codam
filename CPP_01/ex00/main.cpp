/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:05:28 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 16:20:40 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie* first_zombie = newZombie("Harry");
	first_zombie->announce();
	randomChump("Barry");
	delete (first_zombie);
	return (0);
}