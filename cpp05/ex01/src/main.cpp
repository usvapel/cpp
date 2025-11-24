#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::optional<Bureaucrat> a;
	std::optional<Form> form;

	try {
		a.emplace(11, "Timmy");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (a.has_value()) {
		std::cout << *a;
		std::cout << a->getGrade() << std::endl << std::endl;
	} else {
		std::cout << a->getName() << " not constructed" << '\n';
		return 0;
	}

	try {              //name //sign //execute
		form.emplace("form", 0, 5);
	} catch (const Form::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Form::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}
	
	if (form.has_value()) {
		std::cout << *form;
	} else {
		std::cout << form->get_name() << " not constructed" << '\n';
		return 0;
	}

	std::cout << a->getName() << " grade: " << a->getGrade() << '\n';
	a->signForm(*form);
	std::cout << "is form signed? " << (form->is_signed() ? "true" : "false") << '\n';
	a->inc_grade();
	std::cout << a->getName() << " grade: " << a->getGrade() << '\n';
	a->signForm(*form);
	std::cout << "is form signed? " << (form->is_signed() ? "true" : "false") << '\n';

}
