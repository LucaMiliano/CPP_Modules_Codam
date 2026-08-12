#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Bureaucrat;

class Form{
	private:
		const std::string name;
		bool _isSigned;
		const int gradeToSign;
		const int gradeToExecute;

	public:
		Form(std::string const name, int const gradeToSign, int const gradeToExecute);
		~Form();
		Form &operator=(const Form &other);
		Form(const Form &other);
		std::ostream &operator<<(const Form &form);
		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const Bureaucrat &b);

		class GradeTooHighException : public std::exception {
		public:
			const char *what() const noexcept override;
		};
		class GradeTooLowException : public std::exception {
		public:
			const char *what() const noexcept override;
		};

};