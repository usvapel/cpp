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

void	Harl::debug(void)
{
	std::cout << "error";
}

void	Harl::info(void)
{
	std::cout << "error";

}

void	Harl::warning(void)
{
	std::cout << "error";

}

void	Harl::error(void)
{
	std::cout << "error";

}

void	Harl::complain(std::string level)
{
	void (*f[])() = { debug, info, warning, error };
}
