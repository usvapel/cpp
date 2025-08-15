/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:05:22 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/13 19:05:24 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cout << "usage: ./harlFilter DEBUG, INFO, WARNING, ERROR" << std::endl;
		return 0;
	}

	Harl harl;
	harl.complain(av[1]);

	return 0;
}
