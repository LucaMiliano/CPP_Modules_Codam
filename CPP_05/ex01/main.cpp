#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
	Bureaucrat b1("Luca", 1);
	Bureaucrat b2("Franklin", 150);
	Bureaucrat b3("John", 75);

	Form f1("TopSecret", 1, 10);
	Form f2("Routine", 150, 150);
	Form f3("Mid", 75, 100);

	std::cout << "Initial forms:\n";
	std::cout << "- " << f1.getName() << ", signed: " << (f1.getIsSigned() ? "yes" : "no") << ", sign grade: " << f1.getGradeToSign() << std::endl;
	std::cout << "- " << f2.getName() << ", signed: " << (f2.getIsSigned() ? "yes" : "no") << ", sign grade: " << f2.getGradeToSign() << std::endl;
	std::cout << "- " << f3.getName() << ", signed: " << (f3.getIsSigned() ? "yes" : "no") << ", sign grade: " << f3.getGradeToSign() << std::endl;

	std::cout << "\nTest: b3 (grade 75) signs f3 (needs 75):\n";
	b3.signForm(f3);
	std::cout << "f3 signed? " << (f3.getIsSigned() ? "yes" : "no") << std::endl;

	std::cout << "\nTest: b2 (grade 150) tries to sign f1 (needs 1):\n";
	b2.signForm(f1);
	std::cout << "f1 signed? " << (f1.getIsSigned() ? "yes" : "no") << std::endl;

	std::cout << "\nTest: b1 (grade 1) signs f1 (needs 1):\n";
	b1.signForm(f1);
	std::cout << "f1 signed? " << (f1.getIsSigned() ? "yes" : "no") << std::endl;

	std::cout << "\nTest: b2 signs f2 (needs 150):\n";
	b2.signForm(f2);
	std::cout << "f2 signed? " << (f2.getIsSigned() ? "yes" : "no") << std::endl;

	std::cout << "\nDirect exception test: attempt f1.beSigned(b2) (should throw):\n";
	try {
		f1.beSigned(b2);
	} catch (const Form::GradeTooLowException &e) {
		std::cout << "Caught expected exception: " << e.what() << std::endl;
	}

	return 0;
}