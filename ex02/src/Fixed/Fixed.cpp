/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:24:08 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 19:41:43 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->rawBits = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int intValue)
{
	std::cout << "Int constructor called" << std::endl;
	this->rawBits = intValue << fractional;
}

Fixed::Fixed(const float floatValue)
{
	std::cout << "Float constructor called" << std::endl;
	this->rawBits = roundf(floatValue * (1 << fractional));
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

float	Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) / (1 << fractional));
}

int		Fixed::toInt(void) const
{
	return (this->rawBits >> fractional);
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return (out);
}

bool Fixed::operator> (const Fixed &other) const
{
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator< (const Fixed &other) const
{
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->rawBits <= other.rawBits);
}

bool Fixed::operator==(const Fixed &other) const
{
	return (this->rawBits == other.rawBits);
}

bool Fixed::operator!=(const Fixed &other) const
{
	return (this->rawBits != other.rawBits);
}


Fixed Fixed::operator+(const Fixed &other) const
{
	return (Fixed(this->toFloat() + other.toFloat()));
}

Fixed Fixed::operator-(const Fixed &other) const
{
	return (Fixed(this->toFloat() - other.toFloat()));
}

Fixed Fixed::operator*(const Fixed &other) const
{
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.rawBits == 0)
	{
		std::cerr << "Error: División por cero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed &Fixed::operator++()
{
	this->rawBits += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->rawBits += 1;
	return temp;
}

Fixed &Fixed::operator--()
{
	this->rawBits -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->rawBits -= 1;
	return temp;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a < b)
		return (a);
	return (b);
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a > b)
		return (a);
	return (b);
}
