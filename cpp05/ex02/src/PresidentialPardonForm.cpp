#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string _target) : 
			AForm("PresidentialPardonForm", 25, 5),
			target(_target)
{};

PresidentialPardonForm::~PresidentialPardonForm() {};

const std::string PresidentialPardonForm::get_name() const {
	return AForm::get_name();
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
	AForm::check_requirements(executor);
	std::cout << get_name() << ": "+target << " has been pardoned by Zaphod Beeblebrox ?" << '\n';
}
