/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 17:47:32 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/11 17:47:38 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::get_first_name()
{
	return first_name;
}

static std::string get_input(const std::string &prompt)
{
	std::string input;

	do {
		std::cout << prompt << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			return ("");
	} while (input.empty());

	return (input);
}

static void print_line(std::string& str)
{
	if (str.length() > 10)
		std::cout << std::setw(10) << str.substr(0, 9) + ".";
	else
		std::cout << std::setw(10) << str;
}

void Contact::input_data(Contact &contact)
{
	std::cout << "Enter contact information" << std::endl;

	contact.first_name     = get_input("first name");
	if (contact.first_name.empty())     return ;

	contact.last_name      = get_input("last name");
	if (contact.last_name.empty())      return ;

	contact.nickname       = get_input("nickname");
	if (contact.nickname.empty())       return ;

	contact.phone_number   = get_input("phone number");
	if (contact.phone_number.empty())   return ;

	contact.darkest_secret = get_input("darkest secret");
	if (contact.darkest_secret.empty()) return ;
}

void Contact::print_contacts(Contact contacts[], int contact_amount)
{
	for (int i = 0; i < contact_amount; i++) {
		std::cout << std::setw(10) << std::left << i + 1 << "|";
		print_line(contacts[i].first_name); std::cout << "|";
		print_line(contacts[i].last_name);  std::cout << "|";
		print_line(contacts[i].nickname);   std::cout << std::endl;
	}
}

void Contact::print_single_contact(Contact contacts[], int index)
{
	std::cout << "first name:     ";
	std::cout << contacts[index - 1].first_name     << std::endl;

	std::cout << "last name:      ";
	std::cout << contacts[index - 1].last_name      << std::endl;

	std::cout << "nickname:       ";
	std::cout << contacts[index - 1].nickname       << std::endl;

	std::cout << "phone number:   ";
	std::cout << contacts[index - 1].phone_number   << std::endl;

	std::cout << "darkest secret: ";
	std::cout << contacts[index - 1].darkest_secret << std::endl;
}
