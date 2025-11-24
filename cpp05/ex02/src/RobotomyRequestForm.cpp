#include "RobotomyRequestForm.hpp"
#include <random>

RobotomyRequestForm::RobotomyRequestForm(const std::string _target) : 
			AForm("RobotomyRequestForm", 72, 45),
			target(_target)
{};

RobotomyRequestForm::~RobotomyRequestForm() {};

const std::string RobotomyRequestForm::get_name() const {
	return AForm::get_name();
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
	AForm::check_requirements(executor);
	std::cout << get_name() << ": some drilling noises ?" << '\n';

	// generate random number between 1 - 2 with equal chance using Mersenne Twister
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(1, 2);

	if (distrib(gen) == 1) {
		std::cout << get_name() << ": "+target << " has been robotomized!" << '\n';
	} else {
		std::cout << get_name() << ": robotomy failed on " << target << '\n';
	}
}
