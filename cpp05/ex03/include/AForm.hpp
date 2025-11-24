#pragma once

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
	void check_requirements(const Bureaucrat &obj) const;
	virtual void execute(const Bureaucrat &executor) const;

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
