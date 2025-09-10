/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:40:21 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/22 19:40:48 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Animal.hpp"
#include "colors.hpp"

class Dog : public Animal
{
	public:
		Dog();
		Dog(const Dog& obj);
		Dog& operator = (const Dog& obj);
		~Dog();
		void makeSound() const;
};
