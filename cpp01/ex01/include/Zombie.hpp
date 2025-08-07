/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:04:14 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/07 14:04:50 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Zombie
{
	public:
		void announce(void);
		void set_name(std::string _name);
		~Zombie();
	private:
		std::string name;
};

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);
Zombie *zombieHorde(int N, std::string name);
