/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 16:25:12 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 16:58:47 by lpieck           ###   ########.fr       */
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

Zombie* zombieHorde( int N, std::string name );




#endif