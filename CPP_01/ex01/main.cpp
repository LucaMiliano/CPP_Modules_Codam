/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:25:04 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 17:21:48 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	int amount_of_zombies = 5;
	Zombie* horde = zombieHorde(amount_of_zombies, "Ben");
	
	delete[] horde;
	return (0);
}