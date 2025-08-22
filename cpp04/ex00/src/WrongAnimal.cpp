/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:31:01 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 20:31:03 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	type = "Maybe an animal, maybe not";
}

WrongAnimal::~WrongAnimal() {}

WrongAnimal::WrongAnimal(const WrongAnimal& obj) {
	*this = obj;
}

WrongAnimal& WrongAnimal::operator = (const WrongAnimal& obj) {
	if (this == &obj)
		return *this;
	this->type = obj.type;
	return *this;
}

void WrongAnimal::makeSound() const {
	std::cout << "WrongAnimal sounds.." << std::endl;
}

std::string WrongAnimal::getType() const {
	return type;
}
