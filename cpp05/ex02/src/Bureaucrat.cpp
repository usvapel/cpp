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
#include "AForm.hpp"

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

void Bureaucrat::signForm(AForm &form) { 
	try {
		form.beSigned(*this);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << getName() << " couldn't sign " << form.get_name() << " because " << e.what() << '\n';
		return ;
	}
	std::cout << getName() << " successfully signed " << form.get_name() << '\n';
}

Bureaucrat::Bureaucrat(int _grade, const std::string& _name) : name(_name) {
	if (_grade < 1)
		throw GradeTooHighException("Cannot initialize Bureaucrat: grade too high");
	else if (_grade > 150)
		throw GradeTooLowException("Cannot initialize Bureaucrat: grade too low");
	else
		grade = _grade;
}

void Bureaucrat::executeForm(AForm const& form) {
	if (getGrade() <= form.get_required_execute_grade()) {
		form.execute();
		std::cout << getName() << " executed " << form.get_name() << '\n';
	} else {
		std::cout << getName() << " couldn't execute form " << form.get_name() << ". grade too low" << '\n';
	}
}
