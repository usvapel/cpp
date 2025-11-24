#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	// create bureaucrat
	std::optional<Bureaucrat> crat;

	try {
		crat.emplace(1, "Timmy");
	} catch (const Bureaucrat::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const Bureaucrat::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (crat.has_value()) {
		std::cout << *crat;
	} else {
		std::cout << crat->getName() << " not constructed" << '\n';
		return 0;
	}


	std::cout << '\n';


	// create shrubbery form
	std::optional<ShrubberyCreationForm> shrub;

	try {
		shrub.emplace("shrub");
	} catch (const AForm::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	if (shrub.has_value()) {
		std::cout << *shrub << '\n';
	} else {
		std::cout << shrub->get_name() << " not constructed" << '\n';
		return 0;
	}

	// try singing shrubbery
	try {
		crat->signForm(*shrub);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	// try executing shrubbery
	try {
		crat->executeForm(*shrub);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	
	std::cout << '\n';


	// create robotomy form
	std::optional<RobotomyRequestForm> robo;

	try {
		robo.emplace("robo");
	} catch (const AForm::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}
	
	if (robo.has_value()) {
		std::cout << *robo << '\n';
	} else {
		std::cout << robo->get_name() << " not constructed" << '\n';
		return 0;
	}

	// try signing robotomy
	try {
		crat->signForm(*robo);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	// try executing robotomy
	try {
		crat->executeForm(*robo);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	std::cout << '\n';


	// create president form
	std::optional<PresidentialPardonForm> pres;

	try {
		pres.emplace("pres");
	} catch (const AForm::GradeTooHighException& e) {
		std::cout << e.what() << '\n';
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}
	
	if (pres.has_value()) {
		std::cout << *pres << '\n';
	} else {
		std::cout << pres->get_name() << " not constructed" << '\n';
		return 0;
	}

	// try signing president
	try {
		crat->signForm(*pres);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}

	// try executing president
	try {
		crat->executeForm(*pres);
	} catch (const AForm::GradeTooLowException& e) {
		std::cout << e.what() << '\n';
	}
}
