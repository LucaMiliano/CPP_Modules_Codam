/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 14:54:41 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 18:31:26 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON
#define WEAPON 
#include <string>

class Weapon{
	private:
		std::string type;

	public:
	Weapon(std::string weapon_type);
		const std::string& getType() const;
		void setType(const std::string& newType);
};

#endif