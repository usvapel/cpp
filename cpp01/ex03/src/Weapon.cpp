/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:57:52 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/07 23:14:53 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string _type) : type(_type)
{
}

void Weapon::setType(std::string _type)
{
	type = _type;
}

const std::string& Weapon::getType() const
{
	return type;
}