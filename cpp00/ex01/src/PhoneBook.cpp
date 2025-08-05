/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 18:15:09 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/05 18:15:26 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

void	PhoneBook::getdata()
{
	cout<<"          PhoneBook\n";
	cout<<"Available commands: ADD, SEARCH, EXIT\n";
	cout<<"Enter command\n";
	cout<<"> ";
	cin>>contact;
}

void	PhoneBook::putdata()
{
	cout<<contact<<" ";
	cout<<endl;
}
