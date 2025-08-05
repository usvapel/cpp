/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:07:07 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/05 18:15:06 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include "Contact.hpp"

class PhoneBook
{
	std::string contact;
	private:
		Contact contacts[8];
		int	contact_limit;
	public:
		void	getdata();
		void	putdata();
};


