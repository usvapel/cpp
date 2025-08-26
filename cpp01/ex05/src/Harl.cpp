/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 19:05:25 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/13 19:05:32 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug(void) {
	std::cout << "debug!" << std::endl;
}

void	Harl::info(void) {
	std::cout << "info!" << std::endl;
}

void	Harl::warning(void) {
	std::cout << "warning!" << std::endl;

}

void	Harl::error(void) {
	std::cout << "error!" << std::endl;
}

void	Harl::complain(std::string level) {
	void (Harl::*actions[])() = {
		&Harl::debug, 
		&Harl::info, 
		&Harl::warning, 
		&Harl::error
	};

	const std::string array[] = {
		DEBUG,
		INFO,
		WARNING,
		ERROR
	};

	for (int i = 0; i < 4; i++)
		if (level == array[i])
			for (;  i < 4; i++)
				(this->*actions[i])();
}
