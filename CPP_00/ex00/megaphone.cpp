/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 16:03:16 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/24 16:16:45 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

void capitalize_string(char *str)
{
	int i = 0;
	
	while (str[i])
	{
		std::cout << static_cast<char>(std::toupper(str[i]));
		i++;
	}
}
int main(int argc, char **argv)
{
	if (argc == 1)
	std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		int i = 1;
		while (i < argc)
		{
			capitalize_string(argv[i]);
			std::cout << " ";
			i++;
		}
	}
	std::cout << std::endl;
	return (0);
}