/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpieck <lpieck@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 15:47:10 by lpieck            #+#    #+#             */
/*   Updated: 2026/03/12 17:23:49 by lpieck           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED
#define FIXED

#include <iostream>
#include <cmath>

class Fixed{
	private:
		int number;
		static const int bits = 8;
	
	public:
		Fixed();
		Fixed(const int number);
		Fixed(const double fl_number);
		Fixed(const Fixed& other);
		Fixed& operator=(const Fixed& other);
		Fixed& operator>(const Fixed& other);
		Fixed& operator<(const Fixed& other);
		Fixed& operator>=(const Fixed& other);
		Fixed& operator<=(const Fixed& other);
		Fixed& operator==(const Fixed& other);
		Fixed& operator!=(const Fixed& other);
		Fixed& operator+(const Fixed& other);
		Fixed& operator-(const Fixed& other);
		Fixed& operator*(const Fixed& other);
		Fixed& operator/(const Fixed& other);
		~Fixed();
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif