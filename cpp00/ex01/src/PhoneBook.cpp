/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:15:09 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/05 23:53:19 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : contact_limit(0), contact_amount(0) {}

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

int PhoneBook::search_contacts()
{
	std::int32_t input {};
	std::cout << "Available contacts:" << std::endl;

	if (contact_amount == 0) {
		std::cout << "None" << std::endl;
		return 0;
	}

	Contact::print_contacts(contacts, contact_amount);

	while (true) {
		command = get_input("Expand a contact");
		if (command.empty()) return (1);

		try {
			input = std::stoi(command);
		} catch (std::out_of_range const &ex) {
			std::cout << "invalid input! Value is out of range." << std::endl;
			continue ;
		} catch (std::invalid_argument const &ex) {
			std::cout << "invalid input! Please enter a number." << std::endl;
			continue ;
		}

		if (input <= contact_amount && input > 0)
			break ;

		std::cout << "Invalid index! -- available contacts: " << contact_amount << std::endl;
	}
	Contact::print_single_contact(contacts, input);
	return 0;
}

void PhoneBook::getdata()
{
	std::int32_t index;

	std::cout << "PhoneBook" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;

	while (true) {
		command = get_input("Enter command");
		if (command.empty()) return ;

		if (command == "ADD") {
			index = contact_limit % 8;
			Contact::input_data(contacts[index]);
			if (!contacts[index].get_first_name().empty()) {
				contact_limit++;
				if (contact_amount < 8)
					contact_amount++;
			}
		}

		if (command == "SEARCH")
			if (search_contacts() == 1) return ;

		if (command == "EXIT")
			exit(0);
	}
}
