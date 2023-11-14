/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 16:12:08 by asaber            #+#    #+#             */
/*   Updated: 2023/11/14 21:36:02 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->nbr = 0;
}

Fixed::Fixed(int nbr)
{
	std::cout << "Int constructor called" << std::endl;
	this->nbr = nbr << this->bits;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const float nbr)
{
	std::cout << "Float constructor called" << std::endl;
	this->nbr = roundf(nbr * (1 << this->bits));
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->nbr = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
		this->nbr = other.getRawBits();;
		return (*this);
}


std::ostream& operator <<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

float	Fixed::toFloat() const
{
	return ((float) this->nbr / (1 << this->bits));
}

int	Fixed::toInt() const
{
	return (this->nbr >> this->bits);
}

int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->nbr);
}

void	Fixed::setRawBits(int const	raw)
{
	this->nbr = raw;
}