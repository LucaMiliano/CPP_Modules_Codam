/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:47:10 by lpieck            #+#    #+#             */
/*   Updated: 2026/03/26 14:16:07 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	this->number = 0;
}

Fixed::Fixed(const Fixed& other){
	this->number = other.getRawBits();
}


Fixed& Fixed::operator=(const Fixed& other){
	if (this != &other)
		this->number = other.getRawBits();
	return (*this);
}

Fixed::~Fixed(){
}

void Fixed::setRawBits(int const raw)
{
	this->number = raw;
}

int Fixed::getRawBits(void) const {
	return (this->number);
}

Fixed::Fixed(const int n)
{
	this->number = n << bits;
}

Fixed::Fixed(const double fl)
{
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

bool Fixed::operator>(const Fixed& other) const
{
	return (this->number > other.number);
}

bool Fixed::operator<(const Fixed& other) const
{
	return (this->number < other.number);
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (this->number >= other.number);
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (this->number <= other.number);
}

bool Fixed::operator==(const Fixed& other) const
{
	return (this->number == other.number);
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (this->number != other.number);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed& other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed& other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed& other) const
{
	return (Fixed(this->toFloat() / other.toFloat()));
}

Fixed& Fixed::operator++()
{
	this->number++;
	return (*this);
}

//check
Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->number++;
	return (temp);
}

Fixed& Fixed::operator--()
{
	this->number--;
	return (*this);
}

//check
Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->number--;
	return (temp);
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b ? a : b);
}