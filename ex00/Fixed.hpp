/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:25:00 by asaber            #+#    #+#             */
/*   Updated: 2023/11/12 22:56:21 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define	FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int	fixed;
		const	static int	bits = 8;
	public:
		Fixed(void);
		~Fixed(void);
		Fixed(const	Fixed& other);
		Fixed& operator=(const Fixed& other);
		int getRawBits( void ) const;
		void setRawBits( int const raw );		
};


#endif