/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:42:16 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 19:42:24 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal() {
	type = "Maybe an animal, maybe not";
}

Animal::~Animal() {}

Animal::Animal(const Animal& obj) {
	*this = obj;
}

Animal& Animal::operator = (const Animal& obj) {
	if (this == &obj)
		return *this;
	this->type = obj.type;
	return *this;
}

void Animal::makeSound() const {
	std::cout << "Animal sounds.." << std::endl;
}

std::string Animal::getType() const {
	return type;
}
