/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:19:14 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 20:31:08 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"
#include <cmath>

static Fixed area(Point const &p1, Point const &p2, Point const &p3)
{
	float x1 = p1.getX().toFloat();
	float y1 = p1.getY().toFloat();
	float x2 = p2.getX().toFloat();
	float y2 = p2.getY().toFloat();
	float x3 = p3.getX().toFloat();
	float y3 = p3.getY().toFloat();

	float determinant =	(x1 * (y2 - y3)) +
						(x2 * (y3 - y1)) +
						(x3 * (y1 - y2));
	float result = 0.5f * std::fabs(determinant);
	return Fixed(result);
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed A_total = area(a, b, c);
	Fixed A1 = area(point, b, c);
	Fixed A2 = area(a, point, c);
	Fixed A3 = area(a, b, point);

	if (A_total == (A1 + A2 + A3))
	{
		if (A1 == Fixed(0) || A2 == Fixed(0) || A3 == Fixed(0))
			return false;
		return true;
	}
	return false;
}
