#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
  private:
	ShrubberyCreationForm();
	const std::string target;

  public:
	ShrubberyCreationForm(const std::string _target);
	ShrubberyCreationForm(const ShrubberyCreationForm &obj) = delete;
	ShrubberyCreationForm operator=(const ShrubberyCreationForm &obj) = delete;
	~ShrubberyCreationForm();
	const std::string get_name() const override;
	void execute(const Bureaucrat &executor) const override;
};
