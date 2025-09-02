/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 13:52:50 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/02 13:53:16 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat& obj) {
	*this = obj;
}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat& obj) {
	if (this == &obj)
		return *this;
	this->grade = obj.grade;
	return *this;
}

std::ostream& operator << (std::ostream& os, const Bureaucrat& obj) {
	(void)obj;
	os << "hello\n";
	return os;
}

Bureaucrat::Bureaucrat(int _grade, const std::string _name) : name(_name) {
	if (_grade < 1)
		throw Bureaucrat::GradeTooHighException;
	else if (_grade > 150)
		throw Bureaucrat::GradeTooLowException;
	else
		grade = _grade;
}
