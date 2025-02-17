/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:24:08 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 18:57:27 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed()
{
	this->rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}
Fixed::Fixed(const Fixed &other)
{
	this->rawBits = other.getRawBits();
	std::cout << "Copy constructor called" << std::endl;
}
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->rawBits = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return (*this);
}
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return (this->rawBits);
}
void	Fixed::setRawBits(int const rawBits)
{
	this->rawBits = rawBits;
}
