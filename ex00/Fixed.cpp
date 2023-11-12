/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaber <asaber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 22:43:40 by asaber            #+#    #+#             */
/*   Updated: 2023/11/12 23:05:29 by asaber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	this->fixed = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->fixed = other.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& other)
{
        std::cout << "Copy assignment operator called" << std::endl;
        if (this != &other)
			this->fixed = other.getRawBits();
        return *this;
}
int	Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->fixed);
}

void	Fixed::setRawBits(int const	raw)
{
	this->fixed = raw;
}