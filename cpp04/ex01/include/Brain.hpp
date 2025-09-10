/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/23 13:27:13 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/23 13:51:02 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

class Brain
{
	protected:
		std::string ideas[100];
	public:
		Brain();
		Brain(const Brain& obj);
		Brain operator = (const Brain& obj);
		~Brain();
};
