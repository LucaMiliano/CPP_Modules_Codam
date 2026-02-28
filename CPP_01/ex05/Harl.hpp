/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 15:02:55 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/28 16:15:35 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL
#define HARL

#include <iostream>
#include <string>

class Harl
{
	private:
		void debug(void);
		void warning(void);
		void info(void);
		void error(void);

		typedef void (Harl::*Level)();
		
	public:
		void complain(std::string level);
};

#endif