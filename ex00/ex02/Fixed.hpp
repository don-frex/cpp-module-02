/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 12:09:28 by asaber            #+#    #+#             */
/*   Updated: 2023/11/14 21:37:21 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define	FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int	nbr;
		const	static int	bits = 8;
	public:
		Fixed(void);
		Fixed(int nbr);
		Fixed(const float nbr);
		~Fixed(void);
		Fixed(const	Fixed& other);
		Fixed& operator=(const Fixed& other);
		bool	operator>(const Fixed& other);
		bool	operator<(const Fixed& other);
		bool	operator>=(const Fixed& other);
		bool	operator<=(const Fixed& other);
		bool	operator==(const Fixed& other);
		bool	operator!=(const Fixed& other);
		int	operator+(const Fixed& other);
		int	operator-(const Fixed& other);
		int	operator*(const Fixed& other);
		int	operator/(const Fixed& other);
		Fixed&	operator++(void);
		Fixed&	operator--(void);
		const Fixed	operator++(int);
		const Fixed operator--(int);
		static	Fixed&	min(Fixed& f_point1, Fixed& f_point2);
		static const	Fixed&	min(Fixed const &f_point1, Fixed const &f_point2 );
		static	Fixed&	max(Fixed& f_point1, Fixed& f_point2);
		static const	Fixed&	max(Fixed const &f_point1, Fixed const &f_point2);
		int getRawBits( void ) const;
		void setRawBits( int const raw );
		float toFloat( void ) const;
		int toInt( void ) const;
};

std::ostream& operator <<(std::ostream &out, const Fixed &fixed);

#endif