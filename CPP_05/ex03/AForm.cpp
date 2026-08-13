#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <iostream>

AForm::AForm(std::string name, int const gradeToSign, int const gradeToExecute)
: name(name), _isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (	gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& other)
: name(other.name), _isSigned(other._isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm& AForm::operator=(AForm const& other)
{
	if (this != &other)
	{
		// name, gradeToSign and gradeToExecute are const, cannot be assigned
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::~AForm() {}

std::string AForm::getName() const { return name; }
bool AForm::getIsSigned() const { return _isSigned; }
int AForm::getGradeToSign() const { return gradeToSign; }
int AForm::getGradeToExecute() const { return gradeToExecute; }

void AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > gradeToSign)
		throw GradeTooLowException();
	else
	_isSigned = true;
}

const char* AForm::GradeTooHighException::what() const noexcept {
	return "The grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept {
	return "The grade is too low";
}

const char* AForm::FormNotSignedException::what() const noexcept {
	return "The form is not signed";
}

std::ostream& operator<<(std::ostream& os, AForm const& f)
{
	os << "Form " << f.getName() << ", signed: " << (f.getIsSigned() ? "yes" : "no")
		<< ", sign grade: " << f.getGradeToSign() << ", exec grade: " << f.getGradeToExecute();
	return os;
}
