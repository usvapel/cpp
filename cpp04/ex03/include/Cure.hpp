/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 12:41:27 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/26 12:45:20 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "AMateria.hpp"
#include <iostream>

class Cure : AMateria
{
	public:
		Cure();
		Cure(const Cure& obj);
		Cure& operator = (const Cure& obj);
		~Cure();
};
