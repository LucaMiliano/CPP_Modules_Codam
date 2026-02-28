/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:02:35 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/28 16:50:19 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "DEBUG DEBUG DEBUG\n";
}
void Harl::warning(void)
{
	std::cout << "WARNING WARNING WARNING\n";
}
void Harl::info(void)
{
	std::cout << "INFO INFO INFO\n";
}
void Harl::error(void)
{
	std::cout << "ERROR ERROR ERROR\n";
}
void Harl::complain(std::string level)
{
	const char *names[] = {"1", "2", "3", "4"};
	Level funcs[] = {
		&Harl::debug,
		&Harl::warning,
		&Harl::info,
		&Harl::error
	};
	
	for (int i = 0; i < 4; i++)
	{
		if (level == names[i])
		{
			(this->*funcs[i])();
			return ;
		}
	}
}