/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:46:05 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/23 13:57:22 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
	std::cout << C_GRY "Cat constructor" C_RST << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::~Cat() {
	std::cout << C_GRY "Cat destructor" C_RST << std::endl;
	if (brain)
		delete brain;
}

Cat::Cat(const Cat& obj) : Animal() {
	std::cout << C_GRY "Cat copy constructor" C_RST << std::endl;
	brain = new Brain(*obj.brain);
}

Cat& Cat::operator = (const Cat& obj) {
	if (this == &obj)
		return *this;
	Animal::operator = (obj);
	if (brain)
		delete brain;
	brain = new Brain(*obj.brain);
	return *this;
}

void Cat::makeSound() const {
	std::cout << "MEOW!!!!" << std::endl;
}
