/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 13:51:31 by lpieck            #+#    #+#             */
/*   Updated: 2026/02/27 14:19:59 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string* ptr = &string;
	std::string& ref = string;

	std::cout << "Memory adress of string: " << &string << ", Value: " << string << std::endl;
	std::cout << "Memory adress of ptr: " << &ptr << ", Value: " << ptr << std::endl;
	std::cout << "Memory adress of ref: " << &ref << ", Value: " << ref << std::endl;
	return (0);
}