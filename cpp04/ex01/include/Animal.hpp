/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:37:01 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 19:39:17 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "colors.hpp"

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		Animal(const Animal& obj);
		Animal& operator = (const Animal& obj);
		virtual ~Animal();
		virtual std::string getType() const;
		virtual void makeSound() const;
};
