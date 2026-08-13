#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;

	public:
		Bureaucrat();
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		const std::string &getName() const;
		int getGrade() const;
		void promote();
		void demote();
		void signForm(AForm &form);
		void executeForm(AForm const &form);
		class GradeTooHighException : public std::exception {
			public:
				const char *what() const noexcept override {
					return "Grade too high";
			}
		};
		class GradeTooLowException : public std::exception {
			public:
				const char *what() const noexcept override {
					return "Grade too low";
				}
		};
};

std::ostream & operator<<(std::ostream & out, Bureaucrat const & bureaucrat);