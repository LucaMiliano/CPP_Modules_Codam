/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:27 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 18:34:10 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A
#define HUMAN_A 
#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA{
	public:
		std::string name;
		Weapon& weapon_a;
		void attack();
		
		HumanA(std::string name, Weapon &weapon_type);
};

#endif