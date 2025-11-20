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
	os	<< "name: "
		<< obj.getName()
		<< '\n'
		<< "grade: "
		<< obj.getGrade()
		<< '\n';
	return os;
}

const std::string& Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::inc_grade() {
	if (grade - 1 < 1) {
		throw GradeTooHighException("Cannot increment grade!");
	} else {
		--grade;
	}
}
void Bureaucrat::dec_grade() {
	if (grade + 1 > 150) {
		throw GradeTooLowException("Cannot decrement grade!");
	} else {
		++grade;
	}
}

Bureaucrat::Bureaucrat(int _grade, const std::string& _name) : name(_name) {
	if (_grade < 1)
		throw GradeTooHighException("Cannot initialize Bureaucrat: grade too high");
	else if (_grade > 150)
		throw GradeTooLowException("Cannot initialize Bureaucrat: grade too low");
	else
		grade = _grade;
}
