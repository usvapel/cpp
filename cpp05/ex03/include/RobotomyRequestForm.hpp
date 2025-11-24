#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class RobotomyRequestForm : public AForm
{
  private:
	RobotomyRequestForm();
	const std::string target;

  public:
	RobotomyRequestForm(const std::string _target);
	RobotomyRequestForm(const RobotomyRequestForm &obj) = delete;
	RobotomyRequestForm operator=(const RobotomyRequestForm &obj) = delete;
	~RobotomyRequestForm();
	const std::string get_name() const override;
	void execute(const Bureaucrat &executor) const override;
};
