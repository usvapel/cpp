/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 16:54:20 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 16:54:56 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ClapTrap.hpp"
#include "colors.hpp"

class FragTrap : virtual public ClapTrap
{
	protected:
		static const int defaultHp = 100;
		static const int defaultEp = 100;
		static const int defaultAd = 30;
	public:
		FragTrap();
		FragTrap(const std::string name);
		FragTrap(const FragTrap& obj);
		FragTrap& operator = (const FragTrap& obj);
		~FragTrap();
		void highFivesGuys(void);
};
