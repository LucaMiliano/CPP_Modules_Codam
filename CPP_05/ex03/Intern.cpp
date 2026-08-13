#include "Intern.hpp"

Intern::Intern() {}

Intern::~Intern() {}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

static AForm * createShrubbery(std::string const & target)
{
	return new ShrubberyCreationForm(target);
}

static AForm * createRobotomy(std::string const & target)
{
	return new RobotomyRequestForm(target);
}

static AForm * createPardon(std::string const & target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string const & formName, std::string const & target)
{
	typedef AForm * (*FormCreator)(std::string const &);

	std::string const names[3] = { "shrubbery creation", "robotomy request", "presidential pardon" };
	FormCreator const creators[3] = { &createShrubbery, &createRobotomy, &createPardon };

	for (int i = 0; i < 3; i++)
	{
		if (names[i] == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return creators[i](target);
		}
	}
	std::cout << "Error: form \"" << formName << "\" does not exist." << std::endl;
	return NULL;
}