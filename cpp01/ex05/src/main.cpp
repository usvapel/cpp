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

int main()
{
	Harl harl;

	std::cout              << "level: debug"   << std::endl;
	harl.complain(DEBUG);

	std::cout << std::endl << "level: info"    << std::endl;
	harl.complain(INFO);
	
	std::cout << std::endl << "level: warning" << std::endl;
	harl.complain(WARNING);
	
	std::cout << std::endl << "level: error"   << std::endl;
	harl.complain(ERROR);

	return 0;
}
