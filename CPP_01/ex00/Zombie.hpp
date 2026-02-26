/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:05:12 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 16:54:03 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE
#define ZOMBIE
#include <iostream>
#include <string>
#include <iomanip>

class Zombie
{
	private:
		std::string name;
	public:
		Zombie();
		void announce(void);
		void name_zombie(std::string name);
		~Zombie();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);



#endif