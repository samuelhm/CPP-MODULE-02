/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:24:08 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 20:34:16 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed()
{
	this->rawBits = 0;
}

Fixed::Fixed(const int intValue)
{
	this->rawBits = intValue << fractional;
}

Fixed::Fixed(const float floatValue)
{
	this->rawBits = roundf(floatValue * (1 << fractional));
}

Fixed::Fixed(const Fixed &other)
{
	this->rawBits = other.getRawBits();
}

Fixed::~Fixed()
{
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->rawBits = other.getRawBits();
	return (*this);
}

int		Fixed::getRawBits(void) const
{
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
	return (Fixed(this->toFloat() * other.toFloat()));
}

Fixed Fixed::operator/(const Fixed &other) const
{
	if (other.rawBits == 0)
	{
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
