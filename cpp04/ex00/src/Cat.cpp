/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:46:05 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 19:46:25 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
}

Cat::~Cat() {}

Cat::Cat(const Cat& obj) {
	*this = obj;
}

Cat& Cat::operator = (const Cat& obj) {
	if (this == &obj)
		return *this;
	this->type = obj.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MEOW!!!!" << std::endl;
}
