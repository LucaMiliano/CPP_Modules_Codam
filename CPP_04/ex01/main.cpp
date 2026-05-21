/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:03:17 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/21 14:48:05 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animals[10];
	int i = 0;
	
	while (i < 10)
	{
		animals[i] = new Dog();
		i++;
		animals[i] = new Cat();
		i++;
	}
	for (int j = 0; j < 10; j++)
	{
		delete animals[j];
	}
	return 0;
}