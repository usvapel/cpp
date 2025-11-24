#include "Bureaucrat.hpp"

int main()
{
	std::optional<Bureaucrat> a;

	try {
		a.emplace(150, "Bureucrat 1");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (a.has_value()) {
		std::cout << *a;
		std::cout << a->getGrade() << std::endl;
		try {
			a->dec_grade();
		} catch (const Bureaucrat::GradeTooLowException& e) {
			std::cout << e.what() << '\n';
		}
		std::cout << a->getGrade() << std::endl << std::endl;
	} else {
		std::cout << a->getName() << " not constructed" << '\n';
	}

	std::optional<Bureaucrat> b;

	try {
		b.emplace(0, "Bureucrat 2");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		b.reset();
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		b.reset();
		std::cout << e.what() << '\n';
	}

	if (b.has_value()) {
		std::cout << *b;
		std::cout << *b;
		std::cout << b->getGrade() << std::endl;

		try {
			b->dec_grade();
		} catch (const Bureaucrat::GradeTooHighException& e) {
			std::cout << e.what() << '\n';
		}
		std::cout << b->getGrade() << std::endl << std::endl;
	} else {
		std::cout << b->getName() << " not constructed" << '\n';
	}
}
