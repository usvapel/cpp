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

static std::string get_input(const std::string& prompt)
{
	std::string input;
	do {
		std::cout << prompt << std::endl;
		std::cout << "> ";
		if (!std::getline(std::cin, input))
			return "";
	} while (input.empty());
	return input;
}

static void	input_data(Contact& contact)
{
	std::cout << "Enter contact information" << std::endl;
	contact.first_name = get_input("first name");
	if (contact.first_name.empty()) return;
	contact.last_name = get_input("last name");
	if (contact.last_name.empty()) return;
	contact.nickname = get_input("nickname");
	if (contact.nickname.empty()) return;
	contact.phone_number = get_input("phone number");
	if (contact.phone_number.empty()) return;
	contact.darkest_secret = get_input("darkest secret");
}

static void print_contacts(Contact contacts[], int contact_amount)
{
	for (int i = 0; i < contact_amount; i++)
	{
		std::cout << std::setw(10) << std::left << i + 1;
		std::cout << "|";
		if (contacts[i].first_name.length() > 10)
			std::cout << std::setw(10) << contacts[i].first_name.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].first_name;
		std::cout << "|";
		if (contacts[i].last_name.length() > 10)
			std::cout << std::setw(10) << contacts[i].last_name.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].last_name;
		std::cout << "|";
		if (contacts[i].nickname.length() > 10)
			std::cout << std::setw(10) << contacts[i].nickname.substr(0, 9) + ".";
		else
			std::cout << std::setw(10) << contacts[i].nickname;
		std::cout << std::endl;
	}
}

static void print_single_contact(Contact contacts[], int index)
{
	std::cout << "first name:     ";
	std::cout << contacts[index - 1].first_name << std::endl;
	std::cout << "last name:      ";
	std::cout << contacts[index - 1].last_name << std::endl;
	std::cout << "nickname:       ";
	std::cout << contacts[index - 1].nickname << std::endl;
	std::cout << "phone number:   ";
	std::cout << contacts[index - 1].phone_number << std::endl;
	std::cout << "darkest secret: ";
	std::cout << contacts[index - 1].darkest_secret << std::endl;
}


void	PhoneBook::getdata()
{
	std::cout << "PhoneBook" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
	while (true)
	{
		command = get_input("Enter command");
		if (command.empty()) return;
		if (command == "ADD")
		{
			int index = contact_limit % 8;
			input_data(contacts[index]);
			if (!contacts[index].first_name.empty())
			{
				contact_limit++;
				if (contact_amount < 8)
					contact_amount++;
			}
		}
		else if (command == "SEARCH")
		{
			std::cout << "Available contacts:" << std::endl;
			print_contacts(contacts, contact_amount);
			while (true)
			{
				command = get_input("Expand a contact");
				if (command.empty()) return;
				if (std::stoi(command) <= contact_amount && std::stoi(command) > 0)
					break ;
				std::cout << "Invalid index! -- available indexes: " << "1 - " << contact_amount << std::endl;
			}
			print_single_contact(contacts, std::stoi(command));
		}
		else if (command == "EXIT")
			exit(0);
	}
}
