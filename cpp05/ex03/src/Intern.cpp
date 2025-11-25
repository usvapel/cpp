#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

int get_form(const std::string form_name) {
	int form_index = 0;
	form_index += form_name.compare("shrubbery creation")  ? 0 : 1;
	form_index += form_name.compare("robotomy request")    ? 0 : 2;
	form_index += form_name.compare("presidential pardon") ? 0 : 3;
	return form_index;
}

AForm *Intern::makeForm(const std::string& form_name, const std::string& form_target) {
	AForm *form = nullptr;
	switch(get_form(form_name)) {
		case 1: form = new ShrubberyCreationForm(form_target);  break;
		case 2: form = new RobotomyRequestForm(form_target);    break;
		case 3: form = new PresidentialPardonForm(form_target); break;
		default: std::cout	<< "couldn't create a form with requested name <"
							<< form_name << ">\n";
				 return form;
	}
	std::cout << "Intern creates " << form_name << '\n';
	return form;
}
