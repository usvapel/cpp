/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 20:31:29 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 20:32:16 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << C_GRY "WrongCat constructor" C_RST << std::endl;
	type = "WrongCat";
}

WrongCat::~WrongCat() {
	std::cout << C_GRY "WrongCat destructor" C_RST << std::endl;
}

WrongCat::WrongCat(const WrongCat& obj) {
	std::cout << C_GRY "WrongCat copy constructor" C_RST << std::endl;
	*this = obj;
}

WrongCat& WrongCat::operator = (const WrongCat& obj) {
	if (this == &obj)
		return *this;
	this->type = obj.type;
	return *this;
}

void WrongCat::makeSound() const {
	std::cout << "Fake cat sounds!!!!" << std::endl;
}
