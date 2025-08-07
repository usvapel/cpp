/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:07:04 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/07 14:07:38 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av)
{
	int horde_size = 5;

	if (ac <= 1)
		goto no_input;

	try {
		horde_size = std::stoi(av[1]);
	} catch (std::out_of_range const &ex) {
		std::cout << "invalid input! Value is out of range." << std::endl;
		return 1;
	} catch (std::invalid_argument const &ex) {
		std::cout << "invalid input! Please enter a number." << std::endl;
		return 1;
	}

no_input:

	if (horde_size < 0) {
		std::cout << "invalid value";
		return 1;
	}

	Zombie *zombie = zombieHorde(horde_size, "zombie");
	if (!zombie) return 1;

	for (int i = 0; i < horde_size; i++)
		zombie[i].announce();

	delete [] zombie;

	return 0;
}
