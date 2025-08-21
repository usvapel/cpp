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

#include "ClapTrap.hpp"

int main()
{
	ClapTrap sonic("sonic");
	ClapTrap shadow("shadow");
	sonic.attack("shadow");
	sonic.beRepaired(10);
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	shadow.attack("sonic");
	return 0;
}
