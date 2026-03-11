/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:47:10 by lpieck            #+#    #+#             */
/*   Updated: 2026/03/11 18:00:50 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	this->number = 0;
}

Fixed::Fixed(const Fixed& other){
	std::cout << "Copy constructor called\n";
	this->number = other.getRawBits();
}


Fixed& Fixed::operator=(const Fixed& other){
	std::cout << "Copy assignment operator called\n";
	
	if (this != &other)
		this->number = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
	std::cout << "Destructor called\n";
}

void Fixed::setRawBits(int const raw)
{
	number = raw;	
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called\n";
	return (this->number);
}
