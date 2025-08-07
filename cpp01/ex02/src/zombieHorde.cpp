/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ZombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:01:15 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/07 18:02:01 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *zombie;

	try {
		zombie = new Zombie[N];
	} catch (std::bad_alloc const &ex) {
		std::cout << "Kindly try a lower value, thank you!" << std::endl;
		return NULL;
	}

	for (int i = 0; i < N; i++)
		zombie[i].set_name(name);

	return zombie;
}
