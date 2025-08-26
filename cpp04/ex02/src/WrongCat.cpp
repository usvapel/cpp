/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:31:29 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/23 13:25:06 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	type = "WrongCat";
}

WrongCat::~WrongCat() {}

WrongCat::WrongCat(const WrongCat& obj) : WrongAnimal() {
	*this = obj;
}

WrongCat& WrongCat::operator = (const WrongCat& obj) {
	if (this == &obj)
		return *this;
	this->type = obj.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Fake cat sounds (not real animal ((fake) animal))!!!!" << std::endl;
}
