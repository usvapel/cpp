#include "Form.hpp"

Form::Form()  : name(nullptr),
			sign_grade_requirement(0),
			execute_grade_requirement(0)
{};

Form::~Form() {};

Form::Form(const std::string _name,
		   const int _sign_grade_requirement,
		   const int _execute_grade_requirement) : name(_name),
			sign_grade_requirement(_sign_grade_requirement),
			execute_grade_requirement(_execute_grade_requirement)
{
	if (sign_grade_requirement > 150)
		throw GradeTooLowException("Cannot initialize form with a grade too low! (1-150)");
	if (sign_grade_requirement < 1)
		throw GradeTooLowException("Cannot initialize form with a grade too high! (1-150)");
};

const std::string Form::get_name() const {
	return name;
}
