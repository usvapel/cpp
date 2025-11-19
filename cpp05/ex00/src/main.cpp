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

int main()
{
	std::optional<Bureaucrat> a;

	try {
		a.emplace(150, "Bureucrat 1");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (a.has_value()) {
		std::cout << *a;
	} else {
		std::cout << "a not constructed" << '\n';
	}
	
	std::cout << a->getGrade() << std::endl;

	try {
		a->dec_grade();
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	std::cout << a->getGrade() << std::endl << std::endl;

	std::optional<Bureaucrat> b;

	try {
		b.emplace(1, "Bureucrat 2");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (b.has_value()) {
		std::cout << *b;
	} else {
		std::cout << "b not constructed" << '\n';
	}
	
	std::cout << b->getGrade() << std::endl;

	try {
		b->inc_grade();
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	}

	std::cout << b->getGrade() << std::endl << std::endl;
}
