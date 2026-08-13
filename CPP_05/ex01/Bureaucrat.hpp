#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Form;

class Bureaucrat {

private:
	const std::string name;
	int grade;

public:
	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	Bureaucrat &operator=(const Bureaucrat &other);
	std::ostream &operator<<(const Bureaucrat &bureaucrat);
	~Bureaucrat();
	const std::string &getName() const;
	int getGrade() const;
	void promote();
	void demote();
	void signForm(Form &form);
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