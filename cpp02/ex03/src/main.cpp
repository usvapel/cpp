/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:12:53 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/21 18:12:54 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int main()
{
	Point a(0, 0); 
	Point b(10, 0);
	Point c(10, 100);
	Point point(54, 50);

	std::cout << "Vertices of the triangle: " << std::endl;
	std::cout << "a x(" << a.get_x() << "), y(" << a.get_y() << ")" << std::endl;
	std::cout << "b x(" << b.get_x() << "), y(" << b.get_y() << ")" << std::endl;
	std::cout << "c x(" << c.get_x() << "), y(" << c.get_y() << ")" << std::endl << std::endl;
	std::cout << "Check if the point is inside the triangle" << std::endl;
	std::cout << "point x(" << point.get_x() << "), y(" <<  point.get_y() << ")" << std::endl;

	if (bsp(a, b, c, point))
		std::cout << "The point is: inside" << std::endl;
	else
		std::cout << "The point is: outside" << std::endl;
	return 0;
}
