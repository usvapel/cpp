/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:49:15 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/08 13:24:28 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

HumanB::HumanB(std::string _name) : name(_name)
{
}

const std::string& HumanB::getName() const
{
	return name;
}

void HumanB::attack()
{
	std::cout << name << " is attacking with " << weapon->getType() << std::endl;
}

void HumanB::setWeapon(Weapon& _weapon)
{
	weapon = &_weapon;
}
