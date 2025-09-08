/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 17:43:18 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 17:43:28 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() {
	std::cout << C_ORG "FragTrap " << C_GRY "Default constructor called" C_RST << std::endl;
}

FragTrap::FragTrap(const std::string _name) : ClapTrap(_name) {
	std::cout << C_ORG "FragTrap " << C_GRY "Assignment constructor called" C_RST << std::endl;
	hp = 100;
	ep = 100;
	ad = 30;
}

FragTrap::~FragTrap() {
	std::cout << C_ORG "FragTrap " << C_GRY "Deconstructor called" C_RST << std::endl;
}

FragTrap::FragTrap(const FragTrap& obj) : ClapTrap(obj) {
	std::cout << C_ORG "FragTrap " << C_GRY "Copy constructor called" C_RST << std::endl;
}

void FragTrap::highFivesGuys(void) {

	if (!check_conditions(hp, ep, name))
		return ;

	std::cout	<< C_ORG "FragTrap " C_RST << name
				<< " high fives positively!"
				<< std::endl;
}
