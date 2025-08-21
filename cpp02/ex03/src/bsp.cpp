/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:45:06 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/21 12:45:45 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed triangle_area(const Fixed x1, const Fixed y1,
				  const Fixed x2, const Fixed y2,
				  const Fixed x3, const Fixed y3) {

	Fixed x1Part = x1.toFloat() * (y2.toFloat() - y3.toFloat());
	Fixed x2Part = x2.toFloat() * (y3.toFloat() - y1.toFloat());
	Fixed x3Part = x3.toFloat() * (y1.toFloat() - y2.toFloat());

	Fixed area = (x1Part.toFloat() + x2Part.toFloat() + x3Part.toFloat()) / 2.0f;

	if (area < 0)
		area = -area;

	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	Fixed areaABC = triangle_area(	a.get_x(), a.get_y(),
									b.get_x(), b.get_y(),
									c.get_x(), c.get_y() );

	if (areaABC == 0) return false;

	Fixed areaPAB = triangle_area(	point.get_x(), point.get_y(),
									a.get_x(), a.get_y(),
									b.get_x(), b.get_y());

	Fixed areaPAC = triangle_area(	point.get_x(), point.get_y(),
									a.get_x(), a.get_y(),
									c.get_x(), c.get_y());

	Fixed areaPBC = triangle_area(	point.get_x(), point.get_y(),
									b.get_x(), b.get_y(),
									c.get_x(), c.get_y());

	if (areaPAB == 0 || areaPAC == 0 || areaPBC == 0) return false;

	return areaABC == (areaPAB + areaPAC + areaPBC);
}
