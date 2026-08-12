#include "Bureaucrat.hpp"

#include "Form.hpp"


Bureaucrat::Bureaucrat() : name("Default"), grade(150) {}

Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade) {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		grade = other.grade;
	}
	return *this;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return name;
}

int Bureaucrat::getGrade() const {
	return grade;
}

void Bureaucrat::promote() {
	if (grade <= 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::demote() {
	if (grade >= 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(Form &form) {
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	} catch (const Form::GradeTooLowException &e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}