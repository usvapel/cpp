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

#include "DiamondTrap.hpp"

int main()
{
	DiamondTrap sonic("sonic");
	DiamondTrap knuckles("knuckles");
	sonic.attack("knuckles");
	knuckles.takeDamage(sonic.getAd());
	sonic.whoAmI();
	return 0;
}
