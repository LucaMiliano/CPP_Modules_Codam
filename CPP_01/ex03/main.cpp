/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:34 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 16:57:35 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

// int main()
// {
// 	HumanA human_a("Harry", "Fork");
// 	HumanB human_b("Barry");
// 	human_a.attack();
// 	human_b.attack();
// 	human_a.weapon_a.setType("Gun");
// 	human_b.weapon_b.setType("Big Fork");
// 	human_b.attack();
// 	human_a.attack();	
// }

int main()
{
{
Weapon club = Weapon("crude spiked club");
HumanA bob("Bob", club);
bob.attack();
club.setType("some other type of club");
bob.attack();
}
{
Weapon club = Weapon("crude spiked club");
HumanB jim("Jim");
jim.setWeapon(club);
jim.attack();
club.setType("some other type of club");
jim.attack();
}
return 0;
}