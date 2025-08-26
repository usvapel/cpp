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

int	main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "usage: ./sed <filename> <search> <replace>" << std::endl;
		return 0;
	}

	std::string file        = av[1];
	std::string searchTerm  = av[2];
	if (searchTerm.empty())
		return 0;
	std::string replaceWith = av[3];

	std::string replace_filename = av[1];
	replace_filename.append(".replace");

	std::ifstream input_file;
	input_file.open(file);
	if (!input_file) {
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}

	std::string line;
	std::string result;

	int			match_amount = 0;
	bool		no_matches_flag = false;
	std::size_t needle = 0;

	while (getline(input_file, line)) {

		needle = line.find(searchTerm);
		if (needle == std::string::npos) {
			result.append(line + "\n");
			continue ;
		}

		no_matches_flag = true;
		while (true) {
			needle = line.find(searchTerm, needle);
			if (needle == std::string::npos)
				break ;
			line.erase(needle, searchTerm.length());
			line.insert(needle, replaceWith);
			needle += 1;
			match_amount++;
		}
		result.append(line + "\n");
	}

	input_file.close();

	if (!no_matches_flag) {
		std::cout	<< "0 matches found! " << std::endl
					<< "No file was created!" << std::endl;
		return 1;
	}

	std::ofstream replacefile;
	replacefile.open(replace_filename);
	if (!replacefile) {
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		return 1;
	}

	replacefile << result;
	replacefile.close();

	std::cout << match_amount     << " matches found!"        << std::endl;
	std::cout << replace_filename << " created successfully!" << std::endl;

	return 0;
}
