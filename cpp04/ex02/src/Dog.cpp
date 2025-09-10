/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:46:26 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/23 13:57:42 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
	std::cout << C_GRY "Dog constructor" C_RST << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog() {
	std::cout << C_GRY "Dog destructor" C_RST << std::endl;
	if (brain)
		delete brain;
}

Dog::Dog(const Dog& obj) : Animal() {
	std::cout << C_GRY "Dog copy constructor" C_RST << std::endl;
	brain = new Brain(*obj.brain);
}

Dog& Dog::operator = (const Dog& obj) {
	if (this == &obj)
		return *this;
	Animal::operator = (obj);
	if (brain)
		delete brain;
	brain = new Brain(*obj.brain);
	return *this;
}

void Dog::makeSound() const {
	std::cout << "WOOF!!!!" << std::endl;
}
