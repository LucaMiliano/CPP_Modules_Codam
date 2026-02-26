/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 14:05:12 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/26 16:01:33 by lpieck           ###   ########.fr       */
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
		// {
		// 	std::cout << name << ": BraiiiiiiinnnzzzZ...";
		// 	return ;
		// }
		void name_zombie(std::string name);
		// {
		// 	this->name = name;
		// 	return ;
		// }
		~Zombie();
};

Zombie* newZombie(std::string name);
void	randomChump(std::string name);



#endif