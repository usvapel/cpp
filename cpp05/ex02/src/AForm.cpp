#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name(nullptr),
			_is_signed(false),
			sign_grade_requirement(0),
			execute_grade_requirement(0)
{};

AForm::~AForm() {};

AForm::AForm(const std::string _name,
		   const int _sign_grade_requirement,
		   const int _execute_grade_requirement) : name(_name),
			_is_signed(false),
			sign_grade_requirement(_sign_grade_requirement),
			execute_grade_requirement(_execute_grade_requirement)
{
	if (sign_grade_requirement > 150)
		throw GradeTooLowException("Cannot initialize form with a grade too low! (1-150)");
	if (sign_grade_requirement < 1)
		throw GradeTooLowException("Cannot initialize form with a grade too high! (1-150)");
};

const std::string AForm::get_name() const {
	return name;
}

bool AForm::is_signed() const {
	return _is_signed;
}

int AForm::get_required_execute_grade() const {
	return execute_grade_requirement;
}

int AForm::get_required_sign_grade() const {
	return sign_grade_requirement;
}

void AForm::beSigned(const Bureaucrat& obj) {
	if (obj.getGrade() <= get_required_sign_grade()) {
		_is_signed = true;
	} else {
		throw GradeTooLowException("grade too low");
	}
}

std::ostream &operator<<(std::ostream &os, const AForm& obj) {
	os	<< "AForm name: " << obj.get_name() << '\n'
		<< "Signed: " << (obj.is_signed() ? "true" : "false") << '\n'
		<< "Required grade to sign: " << obj.get_required_sign_grade() << '\n'
		<< "Required grade to execute: " << obj.get_required_execute_grade() << '\n';
	return os;
}

void AForm::execute() const {}
