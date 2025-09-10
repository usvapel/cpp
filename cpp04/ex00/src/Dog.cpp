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
	std::cout << C_GRY "Dog constructor" C_RST << std::endl;
	type = "Dog";
}

Dog::~Dog() {
	std::cout << C_GRY "Dog destructor" C_RST << std::endl;
}

Dog::Dog(const Dog& obj) {
	std::cout << C_GRY "Dog copy constructor" C_RST << std::endl;
	*this = obj;
}

Dog& Dog::operator = (const Dog& obj) {
	if (this == &obj)
		return *this;
	this->type = obj.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "WOOF!!!!" << std::endl;
}
