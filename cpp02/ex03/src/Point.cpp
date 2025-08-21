/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 13:16:06 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/21 13:16:16 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() {
	*this = Point(0, 0);
}

Point::~Point() {}

Point::Point(const Point& obj) : x(obj.x), y(obj.y) {}

Point::Point(const float _x, const float _y) : x(_x), y(_y) {}

Point& Point::operator = (const Point& obj) {
	if (this == &obj)
		return *this;
	*this = obj;
	return *this;
}

const Fixed& Point::get_x() const {
	return x;
}

const Fixed& Point::get_y() const {
	return y;
}
