/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpelline <jpelline@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 14:12:42 by jpelline          #+#    #+#             */
/*   Updated: 2025/11/24 17:31:58 by jpelline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>

class	Bureaucrat;

class AForm
{
  private:
	AForm();
	const std::string name;
	bool _is_signed;
	const int sign_grade_requirement;
	const int execute_grade_requirement;

  public:
	AForm(const std::string _name, const int _sign_grade_requirement,
		const int _execute_grade_requirement);
	AForm(const AForm &obj) = delete;
	AForm &operator=(const AForm &obj) = delete;
	virtual ~AForm();

	// getters
	virtual const std::string get_name() const = 0;
	bool is_signed() const;
	int get_required_sign_grade() const;
	int get_required_execute_grade() const;
	virtual void execute() const;

	// exceptions
	struct GradeTooHighException : std::runtime_error
	{
		using std::runtime_error::runtime_error;
	};
	struct GradeTooLowException : std::runtime_error
	{
		using std::runtime_error::runtime_error;
	};

	// members
	void beSigned(const Bureaucrat &obj);
};

std::ostream &operator<<(std::ostream &os, const AForm &obj);
