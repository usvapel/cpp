/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:55:03 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/02 13:55:27 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
	std::optional<Bureaucrat> crat;

	try {
		crat.emplace(1, "Timmy");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (crat.has_value()) {
		std::cout << *crat;
		std::cout << crat->getGrade() << std::endl << std::endl;
	} else {
		std::cout << crat->getName() << " not constructed" << '\n';
		return 0;
	}

	std::optional<ShrubberyCreationForm> shrub;

	try {              //name //sign //execute
		shrub.emplace("home");
	} catch (const AForm::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (shrub.has_value()) {
		std::cout << *shrub << '\n';
	} else {
		std::cout << shrub->get_name() << " not constructed" << '\n';
		return 0;
	}
	crat->executeForm(*shrub);
}
