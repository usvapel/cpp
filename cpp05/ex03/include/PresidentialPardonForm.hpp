#pragma once

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <iostream>

class PresidentialPardonForm : public AForm
{
  private:
	PresidentialPardonForm();
	const std::string target;

  public:
	PresidentialPardonForm(const std::string _target);
	PresidentialPardonForm(const PresidentialPardonForm &obj) = delete;
	PresidentialPardonForm operator=(const PresidentialPardonForm &obj) = delete;
	~PresidentialPardonForm();
	const std::string get_name() const override;
	void execute(const Bureaucrat &executor) const override;
};
