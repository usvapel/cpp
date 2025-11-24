#pragma once

#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form {
	private:
		Form();
		const std::string name;
		bool _is_signed;
		const int sign_grade_requirement;
		const int execute_grade_requirement;

	public:
		Form(const std::string _name,
				const int _sign_grade_requirement,
				const int _execute_grade_requirement);
		Form(const Form& obj) = delete;
		Form &operator=(const Form& obj) = delete;
		~Form();


		// getters
		const std::string get_name() const;
		bool is_signed() const;
		int get_required_sign_grade() const;
		int get_required_execute_grade() const;

		// exceptions
		struct GradeTooHighException : std::runtime_error {
			using std::runtime_error::runtime_error;
		};
		struct GradeTooLowException : std::runtime_error {
			using std::runtime_error::runtime_error;
		};

		//members
		void beSigned(const Bureaucrat& obj);
};

std::ostream &operator<<(std::ostream &os, const Form& obj);
