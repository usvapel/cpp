#pragma once

#include <exception>
#include <iostream>
#include <optional>
#include <stdexcept>
#include "Form.hpp"

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

	void signForm(Form& form);

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
