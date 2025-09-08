/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:10:22 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/21 13:15:50 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Fixed.hpp"

class Point
{
	private:
		const Fixed x;
		const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point& obj);
		~Point();
		Point& operator = (const Point& obj) = delete;
		const Fixed& get_x() const;
		const Fixed& get_y() const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);
