/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 12:45:06 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/04 14:08:04 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed find_triangle_area(const Fixed x1, const Fixed y1,
								const Fixed x2, const Fixed y2,
								const Fixed x3, const Fixed y3) {

	Fixed x1Part = x1 * (y2 - y3);
	Fixed x2Part = x2 * (y3 - y1);
	Fixed x3Part = x3 * (y1 - y2);

	Fixed area = (x1Part + x2Part + x3Part) / 2.0f;

	if (area < 0)
		area = -area;

	return area;
}

bool bsp(Point const a, Point const b, Point const c, Point const p) {
	Fixed areaABC = find_triangle_area(	a.get_x(), a.get_y(),
										b.get_x(), b.get_y(),
										c.get_x(), c.get_y() );

	if (areaABC == 0) return false;

	Fixed areaPAB = find_triangle_area(	p.get_x(), p.get_y(),
										a.get_x(), a.get_y(),
										b.get_x(), b.get_y() );

	Fixed areaPAC = find_triangle_area(	p.get_x(), p.get_y(),
										a.get_x(), a.get_y(),
										c.get_x(), c.get_y() );

	Fixed areaPBC = find_triangle_area(	p.get_x(), p.get_y(),
										b.get_x(), b.get_y(),
										c.get_x(), c.get_y() );

	if (areaPAB == 0 || areaPAC == 0 || areaPBC == 0) return false;

	return areaABC == (areaPAB + areaPAC + areaPBC);
}
