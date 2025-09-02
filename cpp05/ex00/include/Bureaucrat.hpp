/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:12:42 by jpelline          #+#    #+#             */
/*   Updated: 2025/08/29 14:17:28 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

class Bureaucrat
{
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(int _grade, const std::string _name);
		Bureaucrat(const Bureaucrat& obj);
		Bureaucrat& operator = (const Bureaucrat& obj);
		~Bureaucrat();

		const std::string& getName() const;
		int getGrade();
		void inc_grade(int _value);
		void dec_grade(int _value);
};

std::ostream& operator << (std::ostream& os, const Bureaucrat& obj);
