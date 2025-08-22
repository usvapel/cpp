/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:46:26 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 19:46:43 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
}

Dog::~Dog() {}

Dog::Dog(const Dog& obj) {
	*this = obj;
}

Dog& Dog::operator = (const Dog& obj) {
	if (this == &obj)
		return *this;
	*this = obj;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "WOOF!!!!" << std::endl;
}
