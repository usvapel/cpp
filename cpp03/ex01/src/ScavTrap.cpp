/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 13:50:45 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 14:45:44 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() {
	std::cout << C_PUR "ScavTrap " << C_GRY "Default constructor called" C_RST << std::endl;
}

ScavTrap::ScavTrap(const std::string _name) : ClapTrap(_name) {
	std::cout << C_PUR "ScavTrap " << C_GRY "Assignment constructor called" C_RST << std::endl;
	hp = 100;
	ep = 50;
	ad = 20;
}

ScavTrap::~ScavTrap() {
	std::cout << C_PUR "ScavTrap " << C_GRY "Deconstructor called" C_RST << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& obj) : ClapTrap(obj) {
	std::cout << C_PUR "ScavTrap " << C_GRY "Copy constructor called" C_RST << std::endl;
}

void ScavTrap::guardGate() {

	if (!check_conditions(hp, ep, name))
		return ;

	std::cout	<< C_PUR "ScavTrap " C_RST << name
				<< " is now a Gate keeper!"
				<< std::endl;
}
