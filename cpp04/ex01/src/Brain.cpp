/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:30:31 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/23 13:53:50 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain() {
	std::cout << C_GRY "Brain constructor" C_RST << std::endl;
}

Brain::~Brain() {
	std::cout << C_GRY "Brain destructor" C_RST << std::endl;
}

Brain::Brain(const Brain& obj) {
	std::cout << C_GRY "Brain copy constructor" C_RST << std::endl;
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];
}

Brain Brain::operator = (const Brain& obj) {
	if (this == &obj)
	return *this;
    
	for (int i = 0; i < 100; i++)
		ideas[i] = obj.ideas[i];

    return *this;
}
