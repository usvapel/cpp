/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 19:35:09 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/08 19:38:42 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"
#include "AMateria.hpp"

std::string const& getName() { return ; }
void equip(AMateria* m);
void unequip(int idx);
void use(int idx, ICharacter& target);
