/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shurtado <shurtado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 18:23:44 by shurtado          #+#    #+#             */
/*   Updated: 2025/02/17 20:29:41 by shurtado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point/Point.hpp"


int main()
{
	Point a(0, 0);
	Point b(10, 0);
	Point c(5, 5);

	Point p_inside(5, 2);
	Point p_outside(10, 10);
	Point p_on_edge(5, 0);
	Point p_vertex(0, 0);

	std::cout << "Punto dentro: " << bsp(a, b, c, p_inside) << std::endl;
	std::cout << "Punto fuera: " << bsp(a, b, c, p_outside) << std::endl;
	std::cout << "Punto en borde: " << bsp(a, b, c, p_on_edge) << std::endl;
	std::cout << "Punto en vértice: " << bsp(a, b, c, p_vertex) << std::endl;

	return 0;
}
