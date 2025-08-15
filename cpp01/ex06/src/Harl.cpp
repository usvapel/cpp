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
	std::cout << "[ DEBUG ]"   << std::endl;
	std::cout << "debug!"      << std::endl;
}

void	Harl::info(void)
{
	std::cout << "[ INFO ]"    << std::endl;
	std::cout << "info!"       << std::endl;
}

void	Harl::warning(void)
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "warning!"    << std::endl;
}

void	Harl::error(void)
{
	std::cout << "[ ERROR ]"   << std::endl;
	std::cout << "error!"      << std::endl;
}

static int options(const std::string& s)
{
	if (s == "DEBUG"   ) return DEBUG;
	if (s == "INFO"    ) return INFO;
	if (s == "WARNING" ) return WARNING;
	if (s == "ERROR"   ) return ERROR;
	return OTHER;
}

void	Harl::complain(std::string level)
{
	void (Harl::*actions[])() = {
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};

	switch (options(level))
	{
		case DEBUG:
			(this->*actions[DEBUG])();

		case INFO:
			(this->*actions[INFO])();

		case WARNING:
			(this->*actions[WARNING])();

		case ERROR:
			(this->*actions[ERROR])();
			break ;

		default:
			std::cout << "[ Probably complaining about insignificant problem ]" << std::endl;
	}
}
