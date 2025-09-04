/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/15 17:28:34 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/04 13:56:17 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() {
	value = 0;
}

Fixed::~Fixed() {}

Fixed::Fixed (const Fixed &obj) {
	value = obj.value;
}

Fixed& Fixed::operator = (const Fixed& obj) {
	if (this == &obj)
		return *this;
	this->value = obj.value;
	return *this;
}

bool Fixed::operator > (const Fixed& obj) const {
	return (this->value > obj.value);
}

bool Fixed::operator < (const Fixed& obj) const {
	return (this->value < obj.value);
}

bool Fixed::operator >= (const Fixed& obj) const {
	return (this->value >= obj.value);
}

bool Fixed::operator <= (const Fixed& obj) const {
	return (this->value <= obj.value);
}

bool Fixed::operator == (const Fixed& obj) const {
	return (this->value == obj.value);
}

bool Fixed::operator != (const Fixed& obj) const {
	return (this->value != obj.value);
}

Fixed Fixed::operator + (const Fixed& obj) const {
	return (this->toFloat() + obj.toFloat());
}

Fixed Fixed::operator - (const Fixed& obj) const {
	return (this->toFloat() - obj.toFloat());
}

Fixed Fixed::operator * (const Fixed& obj) const {
	return Fixed((this->toFloat() * obj.toFloat()));
}

Fixed Fixed::operator / (const Fixed& obj) const {
	return Fixed((this->toFloat()) / obj.toFloat());
}

Fixed Fixed::operator ++ (int) {
	Fixed temp = *this;
	++this->value;
	return (temp);
}

Fixed& Fixed::operator ++ () {
	this->value++;
	return (*this);
}

Fixed Fixed::operator -- (int) {
	Fixed temp = *this;
	--this->value;
	return (temp);
}

Fixed& Fixed::operator -- () {
	this->value--;
	return (*this);
}

Fixed Fixed::operator - () const {
	Fixed temp;
	temp.value = -this->value;
	return (temp);
}

Fixed& Fixed::min(Fixed& obj1, Fixed& obj2) {
	return (obj1 < obj2 ? obj1 : obj2);
}

const Fixed& Fixed::min(const Fixed& obj1, const Fixed& obj2) {
	return (obj1 < obj2 ? obj1 : obj2);
}

Fixed& Fixed::max(Fixed& obj1, Fixed& obj2) {
	return (obj1 > obj2 ? obj1 : obj2);
}

const Fixed& Fixed::max(const Fixed& obj1, const Fixed& obj2) {
	return (obj1 > obj2 ? obj1 : obj2);
}

int Fixed::getRawBits() const {
	return value;
}

void Fixed::setRawBits(int const raw) {
	value = raw;
}

Fixed::Fixed(const int convert_int) {
	value = convert_int * (1 << fractional);
}

Fixed::Fixed(const float convert_float) {
	value = (int)roundf(convert_float * (1 << fractional));
}

float Fixed::toFloat(void) const {
	return ((float)value / (float)(1 << fractional));
}

int Fixed::toInt(void) const {
	return (value) / (1 << fractional);
}

std::ostream& operator << (std::ostream& os, const Fixed& obj) {
	os << obj.toFloat();
	return os;
}
