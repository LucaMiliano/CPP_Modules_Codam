#pragma once

#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern{
	public:
		Intern();
		virtual ~Intern();
		Intern &operator=(const Intern &other);
		Intern(const Intern &other);
		AForm *makeForm(std::string const & formName, std::string const & target);
};