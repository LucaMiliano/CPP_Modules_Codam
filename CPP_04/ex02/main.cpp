/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 11:03:17 by lpieck            #+#    #+#             */
/*   Updated: 2026/05/21 15:00:02 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	// Animal abstractAnimal;
	// abstractAnimal.makeSound();
	Dog dog;
	dog.makeSound();
	Cat cat;
	cat.makeSound();
	return 0;
}