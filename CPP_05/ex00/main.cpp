#include "Bureaucrat.hpp"

int main(void){
	
	Bureaucrat b1("Luca", 1);
	Bureaucrat b2("Franklin", 150);
	Bureaucrat b3("John", 75);

	try{
		std::cout << b3.getName() << " has grade " << b3.getGrade() << std::endl;
		b3.demote();
		std::cout << b3.getName() << " has grade " << b3.getGrade() << std::endl;
		std::cout << "----" << std::endl;

		std::cout << b1.getName() << " has grade " << b1.getGrade() << std::endl;
		b1.promote();
		std::cout << b1.getName() << " has grade " << b1.getGrade() << std::endl;
		std::cout << "----" << std::endl;

		// std::cout << b2.getName() << " has grade " << b2.getGrade() << std::endl;
		// b2.demote();
		// std::cout << b2.getName() << " has grade " << b2.getGrade() << std::endl;
		// std::cout << "----" << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
	}
	return 0;
}