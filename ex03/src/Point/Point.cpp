/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 19:46:25 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 20:21:06 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#include <cmath>

Point::Point() : x(0), y(0)
{
}

Point::Point(float x, float y) : x(x), y(y)
{
}

Point::Point(const Point &other) : x(other.x), y(other.y)
{
}

Point& Point::operator=(const Point &other)
{
	if (this != &other)
	{
		const_cast<Fixed&>(x) = other.x;
		const_cast<Fixed&>(y) = other.y;
	}
	return (*this);
}

Point::~Point()
{
}

Fixed Point::getX() const
{
	return (this->x);
}

Fixed Point::getY() const
{
	return (this->y);
}
