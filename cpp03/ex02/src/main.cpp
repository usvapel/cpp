/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 18:59:03 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/21 19:00:22 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main()
{
	FragTrap sonic("sonic");
	FragTrap knuckles("knuckles");
	sonic.attack("knuckles");
	knuckles.takeDamage(30);
	sonic.attack("knuckles");
	knuckles.takeDamage(30);
	sonic.attack("knuckles");
	knuckles.takeDamage(30);
	sonic.attack("knuckles");
	knuckles.takeDamage(30);
	sonic.attack("knuckles");
	knuckles.takeDamage(30);
	sonic.attack("knuckles");
	knuckles.takeDamage(30);
	sonic.highFivesGuys();
	knuckles.highFivesGuys();
	return 0;
}
