/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 17:55:33 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/12 17:55:41 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "error" << std::endl; return 0; }
	std::string searchTerm  = av[2];
	std::string replaceWith = av[3];
	std::string file        = av[1];
	std::ifstream input_stream(file);
	if (!input_stream) std::cerr << "error with file";
	std::string line;
	while (getline(input_stream, line))
	{
		std::size_t found = line.find(searchTerm);
		if (found == std::string::npos) {
			std::cout << line << std::endl;
			continue ;
		}
		line.erase(found, searchTerm.length());
		line.insert(found, replaceWith);
		std::cout << line << std::endl;
		while (true)
		{
			found = line.find(searchTerm, found + 1);
			if (found == std::string::npos)
				break ;
			line.erase(found, searchTerm.length());
			line.insert(found, replaceWith);
			std::cout << line << std::endl;
		}
	}
	return 0;
}
