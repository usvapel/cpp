/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 17:01:54 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/05 17:02:33 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>

int main(int ac, char **av)
{
	int i;

	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	else
	{
		i = 1;
		while (av[i])
		{
			std::string str(av[i]);
			std::transform(
				str.begin(),
				str.end(),
				str.begin(),
				[](unsigned char c) { return std::toupper(c); }
			);
			std::cout << str;
			i++;
		}
	}
	return 0;
}
