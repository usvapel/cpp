/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:12:42 by jpelline          #+#    #+#             */
/*   Updated: 2025/09/08 21:12:01 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>

class Form {
	private:
		const std::string name;
		bool _is_signed;
		const int sign_grade_requirement;
		const int execute_grade_requirement;

	public:
		Form();
		Form &operator=(const Form& obj) = delete;
		Form(const Form& obj) = delete;
		~Form();

		Form(const std::string _name, const int _sign_grade_requirement, const int _execute_grade_requirement);
		// getters
		const std::string get_name() const;
		bool is_signed() const;
		int required_sign_grade() const;
		int required_execute_grade() const;

		// exceptions
		struct GradeTooHighException : std::runtime_error {
			using std::runtime_error::runtime_error;
		};
		struct GradeTooLowException : std::runtime_error {
			using std::runtime_error::runtime_error;
		};

		//members
		void beSigned(const Bureaucrat& obj);
};

std::ostream &operator<<(std::ostream &os, const Form& obj);
