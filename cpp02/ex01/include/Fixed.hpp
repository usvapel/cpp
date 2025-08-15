/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:17:41 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/15 17:27:25 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Fixed
{
	private:
		int	value;
		static const int fractional = 8;
	public:
		Fixed();
		Fixed(const Fixed& obj);
		Fixed& operator = (const Fixed& other);
		~Fixed();

		int getRawBits(void) const;
		void setRawBits(int const raw);
		
		Fixed(const int convert_int);
		Fixed(const float convert_float);

		float toFloat(void) const;
		int toInt(void) const;

		Fixed& operator << (const Fixed& value);
};
