#include "Form.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

Form::Form(std::string name, int const gradeToSign, int const gradeToExecute)
: name(name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(Form const& other)
: name(other.name), _isSigned(other._isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form& Form::operator=(Form const& other)
{
	if (this != &other)
	{
		// name, gradeToSign and gradeToExecute are const, cannot be assigned
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::~Form() {}

std::string Form::getName() const { return name; }
bool Form::getIsSigned() const { return _isSigned; }
int Form::getGradeToSign() const { return gradeToSign; }
int Form::getGradeToExecute() const { return gradeToExecute; }

void Form::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
	_isSigned = true;
}

const char* Form::GradeTooHighException::what() const noexcept {
	return "The grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept {
	return "The grade is too low";
}

std::ostream& operator<<(std::ostream& os, Form const& f)
{
	os << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", sign grade: " << f.getGradeToSign() << ", exec grade: " << f.getGradeToExecute();
	return os;
}
