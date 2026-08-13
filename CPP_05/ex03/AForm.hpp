#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class AForm{
	private:
		const std::string name;
		bool _isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		AForm(std::string const name, int const gradeToSign, int const gradeToExecute);
		virtual ~AForm();
		AForm &operator=(const AForm &other);
		AForm(const AForm &other);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);
		virtual void execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception {
		public:
			const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *what() const noexcept override;
		};
		class FormNotSignedException : public std::exception {
		public:
			const char *what() const noexcept override;
		};
};

std::ostream &operator<<(std::ostream &out, const AForm &form);