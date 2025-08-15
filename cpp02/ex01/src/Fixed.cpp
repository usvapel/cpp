/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:28:34 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/15 17:30:21 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called" << std::endl;
	value = 0;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed (const Fixed &obj)
{
	std::cout << "Copy constructor called" << std::endl;
	value = obj.value;
}

Fixed& Fixed::operator=(const Fixed& other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->value = other.value;
	return *this;
}

int Fixed::getRawBits() const
{
	std::cout << "getRawBits member function called" << std::endl;
	return value;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawbits member function called" << std::endl;
	value = raw;
}

Fixed::Fixed(const int convert_int)
{
	value = convert_int / (1 << fractional);
}

Fixed::Fixed(const float convert_float)
{
	value = convert_float * (1 << fractional);
}

float Fixed::toFloat(void) const
{
	return ((float)value / (1 >> fractional));
}

int Fixed::toInt(void) const
{
	return ((float)value / (1 >> fractional));
}



