/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 22:39:54 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/07 23:10:03 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Weapon
{
	private:
		std::string type;
	public:
		Weapon(std::string _type);
		const std::string &getType() const;
		void		setType(std::string _type);
};

class HumanA
{
	private:
		std::string name;
		Weapon& weapon;
	public:
		HumanA(std::string _name, Weapon& _weapon);
		const std::string& getName() const;
		void attack();
};

class HumanB
{
	Weapon weapon;
	std::string name;
	void attack(std::string _type);
};