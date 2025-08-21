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
#include <cmath>

class Fixed
{
	private:
		int	value;
		static const int fractional = 8;

	public:
		Fixed();
		Fixed(const Fixed& obj);
		~Fixed();

		int  getRawBits(void) const;
		void setRawBits(int   const raw);
		
		Fixed(const int   convert_int);
		Fixed(const float convert_float);

		float toFloat(void) const;
		int   toInt(void)   const;

		Fixed& operator =  (const Fixed& obj);
		bool   operator >  (const Fixed& obj) const;
		bool   operator <  (const Fixed& obj) const;
		bool   operator >= (const Fixed& obj) const;
		bool   operator <= (const Fixed& obj) const;
		bool   operator == (const Fixed& obj) const;
		bool   operator != (const Fixed& obj) const;
		Fixed  operator +  (const Fixed& obj) const;
		Fixed  operator -  (const Fixed& obj) const;
		Fixed  operator *  (const Fixed& obj) const;
		Fixed    operator /  (const Fixed& obj) const;
		Fixed  operator ++ (int);
		Fixed& operator ++ ();
		Fixed  operator -- (int);
		Fixed& operator -- ();
		Fixed  operator - () const;

		static Fixed& min(Fixed& obj1, Fixed& obj2);
		static const  Fixed& min(const Fixed& obj1, const Fixed& obj2);
		static Fixed& max(Fixed& obj1, Fixed& obj2);
		static const  Fixed& max(const Fixed& obj1, const Fixed& obj2);
};

std::ostream& operator << (std::ostream& os, const Fixed& obj);
