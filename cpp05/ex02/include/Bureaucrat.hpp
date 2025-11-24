/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:12:42 by jpelline          #+#    #+#             */
/*   Updated: 2025/11/24 16:47:08 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>

class AForm;

class Bureaucrat
{
  private:
	Bureaucrat();
	const std::string name;
	int grade;

  public:
	Bureaucrat(int _grade, const std::string &_name);
	Bureaucrat(const Bureaucrat &obj);
	Bureaucrat &operator=(const Bureaucrat &obj);
	~Bureaucrat();

	const std::string &getName() const;
	int getGrade() const;
	void inc_grade();
	void dec_grade();

	void signForm(AForm& form);
	void executeForm(const AForm& form);

	struct GradeTooHighException : std::runtime_error
	{
		using std::runtime_error::runtime_error;
	};

	struct GradeTooLowException : std::runtime_error
	{
		using std::runtime_error::runtime_error;
	};
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &obj);
