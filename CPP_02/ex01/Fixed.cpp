/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:47:10 by lpieck            #+#    #+#             */
/*   Updated: 2026/03/12 15:39:32 by lpieck           ###   ########.fr       */
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
	this->number = raw;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called\n";
	return (this->number);
}

Fixed::Fixed(const int n)
{
	std::cout << "Int constructor called\n";
	this->number = n << bits;
}

Fixed::Fixed(const double fl)
{
	std::cout << "Float constructor called\n";
	this->number = static_cast<int>(round(fl * (1 << bits)));
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->number) / (1 << bits);
}

int Fixed::toInt( void ) const {
	return this->number >> bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
	out << fixed.toFloat();
	return (out);
}
