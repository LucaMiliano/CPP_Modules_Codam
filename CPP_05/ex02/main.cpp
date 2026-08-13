#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// NOTE: adjust method names below if yours differ
// (getName, getGrade, incrementGrade, decrementGrade, signForm, executeForm,
//  getIsSigned, getSignGrade, getExecGrade)

static void section(std::string const & title)
{
	std::cout << "\n=== " << title << " ===" << std::endl;
}

int main()
{
	section("Bureaucrat construction: valid + boundaries");
	try
	{
		Bureaucrat b1("Alice", 1);   // highest valid grade
		Bureaucrat b2("Bob", 150);   // lowest valid grade
		std::cout << b1 << std::endl << b2 << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "UNEXPECTED throw: " << e.what() << std::endl;
	}

	section("Bureaucrat construction: invalid grades");
	try
	{
		Bureaucrat bad("TooHigh", -1);
		std::cout << "UNEXPECTED: no throw" << std::endl;
		(void)bad;
	}
	catch (std::exception const & e)
	{
		std::cout << "Caught (expected): " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bad("TooLow", 151);
		std::cout << "UNEXPECTED: no throw" << std::endl;
		(void)bad;
	}
	catch (std::exception const & e)
	{
		std::cout << "Caught (expected): " << e.what() << std::endl;
	}

	section("Grade increment/decrement including limit throws");
	try
	{
		Bureaucrat top("Top", 1);
		top.promote(); // already at 1, should throw
		std::cout << "UNEXPECTED: no throw" << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "Caught (expected): " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bottom("Bottom", 150);
		bottom.demote(); // already at 150, should throw
		std::cout << "UNEXPECTED: no throw" << std::endl;
	}
	catch (std::exception const & e)
	{
		std::cout << "Caught (expected): " << e.what() << std::endl;
	}

	section("ShrubberyCreationForm: sign 145 exec 137");
	{
		ShrubberyCreationForm shrub("home");
		std::cout << shrub << std::endl;

		Bureaucrat weak("Weak", 150);
		Bureaucrat strong("Strong", 1);

		weak.signForm(shrub);    // grade 150 < 145 required -> should fail, prints reason
		strong.signForm(shrub);  // grade 1 <= 145 -> should succeed

		weak.executeForm(shrub);   // signed but grade too low to execute (137 needed)
		strong.executeForm(shrub); // should succeed, writes home_shrubbery
	}

	section("RobotomyRequestForm: sign 72 exec 45, unsigned execution");
	{
		RobotomyRequestForm robo("Bender");
		Bureaucrat exec("Exec", 10);
		exec.executeForm(robo); // not signed yet -> should fail with clear reason
		exec.signForm(robo);    // grade 10 <= 72 -> succeeds
		exec.executeForm(robo); // grade 10 <= 45 -> succeeds, 50% robotomized message
		exec.executeForm(robo); // run again to see randomness in action
	}

	section("PresidentialPardonForm: sign 25 exec 5");
	{
		PresidentialPardonForm pardon("Fred");
		Bureaucrat mid("Mid", 30);
		Bureaucrat president("President", 1);

		mid.signForm(pardon);      // grade 30 > 25 required -> should fail
		president.signForm(pardon); // grade 1 -> succeeds
		mid.executeForm(pardon);    // signed, but grade 30 > 5 required -> should fail
		president.executeForm(pardon); // succeeds
	}

	section("Polymorphism through AForm* (relevant for ex03 too)");
	{
		AForm * forms[3];
		forms[0] = new ShrubberyCreationForm("garden");
		forms[1] = new RobotomyRequestForm("intern");
		forms[2] = new PresidentialPardonForm("felon");

		Bureaucrat guy("Guy", 20);
		for (int i = 0; i < 3; i++)
		{
			std::cout << *forms[i] << std::endl;
			guy.signForm(*forms[i]);
			guy.executeForm(*forms[i]);
			delete forms[i]; // exercises virtual destructor
		}
	}

	section("Copy construction / assignment (OCF check)");
	{
		Bureaucrat original("Original", 50);
		Bureaucrat copy(original);          // copy constructor
		Bureaucrat assigned("Placeholder", 100);
		assigned = original;                // copy assignment

		std::cout << original << std::endl << copy << std::endl << assigned << std::endl;
	}

	return 0;
}