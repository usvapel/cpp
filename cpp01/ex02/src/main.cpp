/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 14:07:04 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/07 22:38:13 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

int main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *ptr  = &brain;
	std::string &ref  = brain;

	std::cout << "address: " << &brain << std::endl;
	std::cout << "address: " << ptr    << std::endl;
	std::cout << "address: " << &ref   << std::endl;

	std::cout << "value:   " << brain  << std::endl;
	std::cout << "value:   " << *ptr   << std::endl;
	std::cout << "value:   " << ref    << std::endl;

	return 0;
}
