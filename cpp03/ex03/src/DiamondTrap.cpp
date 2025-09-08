/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 18:01:14 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 18:01:15 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() {
	std::cout << C_PNK "DiamondTrap " << C_GRY "Default constructor called" C_RST << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& _name) :
													ClapTrap(_name + "_clap_name"),
													FragTrap(_name),
													ScavTrap(_name),
													name(_name) {

	std::cout << C_PNK "DiamondTrap " << C_GRY "Assignment constructor called" C_RST << std::endl;

	hp = FragTrap::defaultHp;
	ep = ScavTrap::defaultEp;
	ad = FragTrap::defaultAd;

}

DiamondTrap::~DiamondTrap() {
	std::cout << C_PNK "DiamondTrap " << C_GRY "Deconstructor called" C_RST << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& obj) : FragTrap(obj), ScavTrap(obj), name(obj.name) {
	std::cout << C_PNK "DiamondTrap " << C_GRY "Copy constructor called" C_RST << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

int DiamondTrap::getAd() { return ad; }

void DiamondTrap::whoAmI() {
	std::cout << C_PNK "DiamondTrap " C_RST << "My name is " << name << std::endl;
	std::cout << C_PNK "DiamondTrap " C_RST << "My ClapTrap name is " << ClapTrap::name << std::endl;
}
