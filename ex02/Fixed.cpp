/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 10:53:00 by asaber            #+#    #+#             */
/*   Updated: 2023/11/14 21:26:29 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Fixed.hpp"

Fixed::Fixed()
{
	//std::cout << "Default constructor called" << std::endl;
	this->nbr = 0;
}

Fixed::Fixed(int nbr)
{
	//std::cout << "Int constructor called" << std::endl;
	this->nbr = nbr ;
}

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const float nbr)
{
	//std::cout << "Float constructor called" << std::endl;
	this->nbr = roundf(nbr * (1 << this->bits));
}

Fixed::Fixed(const Fixed& other)
{
	//std::cout << "Copy constructor called" << std::endl;
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
	//std::cout << "getRawBits member function called" << std::endl;
	return (this->nbr);
}

void	Fixed::setRawBits(int const	raw)
{
	this->nbr = raw;
}

bool Fixed::operator>(const Fixed& other)
{
	return (this->nbr > other.nbr);
}

bool Fixed::operator<(const Fixed& other)
{
	return (this->nbr < other.nbr);
}

bool Fixed::operator>=(const Fixed& other)
{
	return (this->nbr >= other.nbr);
}

bool Fixed::operator<=(const Fixed& other)
{
	return (this->nbr <= other.nbr);
}

bool Fixed::operator==(const Fixed& other)
{
	return (this->nbr == other.nbr);
}

bool Fixed::operator!=(const Fixed& other)
{
	return (this->nbr != other.nbr);
}

int	Fixed::operator+(const Fixed& other)
{
	return (this->nbr + other.nbr);
}

int	Fixed::operator-(const Fixed& other)
{
	return (this->nbr - other.nbr);
}

int	Fixed::operator*(const Fixed& other)
{
	return (this->nbr * other.nbr);
}

int	Fixed::operator/(const Fixed& other)
{
	return (this->nbr / other.nbr);
}

Fixed& Fixed::operator++(void)
{
	this->nbr++;
	return(*this);
}

Fixed& Fixed::operator--(void)
{
	this->nbr--;
	return(*this);
}

const Fixed Fixed::operator++(int)
{
	const Fixed returned(*this);
	this->nbr++;
	return(returned);
}

const Fixed Fixed::operator--(int)
{
	const Fixed returned(*this);
	this->nbr--;
	return(returned);
}

Fixed& Fixed::min(Fixed& f_point1, Fixed& f_point2)
{
	if (f_point1.toFloat() <= f_point2.toFloat())
		return (f_point1);
	return(f_point2);
}

const	Fixed&	Fixed::min(Fixed const &f_point1, Fixed const &f_point2)
{
	if (f_point1.toFloat() <= f_point2.toFloat())
		return (f_point1);
	return(f_point2);
}

Fixed&	Fixed::max(Fixed& f_point1, Fixed& f_point2)
{
	if (f_point1.toFloat() >= f_point2.toFloat())
		return (f_point1);
	return(f_point2);
}

const	Fixed&	Fixed::max(Fixed const &f_point1, Fixed const &f_point2)
{
	if (f_point1.toFloat() >= f_point2.toFloat())
		return (f_point1);
	return(f_point2);
}