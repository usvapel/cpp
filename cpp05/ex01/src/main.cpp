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
#include "Form.hpp"

int main()
{
	std::optional<Bureaucrat> a;
	std::optional<Form> form;

	try {
		a.emplace(150, "Bureucrat 1");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (a.has_value()) {
		std::cout << *a;
		std::cout << a->getGrade() << std::endl << std::endl;
	} else {
		std::cout << a->getName() << " not constructed" << '\n';
	}

	try {
		form.emplace("form", 10, 5);
	} catch (const Form::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Form::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}
	
	if (form.has_value()) {
		std::cout << *form;
	} else {
		std::cout << form->get_name() << " not constructed" << '\n';
	}
}
