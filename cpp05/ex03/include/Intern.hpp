#include <iostream>
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {
	public:
	Intern();
	Intern(const Intern& obj) = delete;
	Intern operator = (const Intern& obj) = delete;
	~Intern();

	AForm *makeForm(const std::string& form_name, const std::string& form_target);
};
