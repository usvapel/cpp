/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:43:22 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/21 18:43:54 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout	<< C_CYN "ClapTrap " C_RST
				<< C_GRY "Default constructor called" C_RST << std::endl;
}

ClapTrap::ClapTrap(std::string _name) : name(_name) {
	std::cout	<< C_CYN "ClapTrap " C_RST
				<< C_GRY "Assignment constructor called" C_RST << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout	<< C_CYN "ClapTrap " C_RST
				<< C_GRY "Deconstructor called" C_RST << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& obj) : name(obj.name), hp(obj.hp), ep(obj.ep), ad(obj.ad) {
	std::cout	<< C_CYN "ClapTrap " C_RST
				<< C_GRY "Copy constructor called" C_RST << std::endl;
}

bool check_conditions(int hp, unsigned int ep, std::string name)
{
	if (hp <= 0) {
		std::cout << C_CYN "ClapTrap " C_RST << name << " is dead!" << std::endl;
		return false;
	}
	if (ep == 0) {
		std::cout << C_CYN "ClapTrap " C_RST << name << " has no energy points left!" << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string& target) {

	if (!check_conditions(hp, ep, name))
		return ;

	std::cout	<< C_CYN "ClapTrap " C_RST << name
				<< " attacks "  << target
				<< ", causing " C_YLW << ad
				<< C_RST " points of damage!"
				<< std::endl;

	ep -= 1;

	std::cout	<< C_CYN "ClapTrap " C_RST << name
				<< " has " C_YLW << ep
				<< C_RST " energy points left!"
				<< std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {

	std::cout	<< C_CYN "ClapTrap " C_RST << name
				<< " got hit for " C_YLW << amount
				<< C_RST " points of damage!"
				<< std::endl;

	hp -= amount;
}

void ClapTrap::beRepaired(unsigned int amount) {

	if (!check_conditions(hp, ep, name))
		return ;

	std::cout	<< C_CYN "ClapTrap " C_RST << name
				<< " is repairing itself for " << amount
				<< " points!"
				<< std::endl;

	hp += amount;
	ep -= 1;

	std::cout	<< C_CYN "ClapTrap " C_RST << name
				<< " has " C_YLW << ep
				<< C_RST " energy points left!"
				<< std::endl;
}
