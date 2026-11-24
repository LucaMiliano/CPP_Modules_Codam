#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib>
#include <iostream>
#include <ctime>


Base *generate(void)
{
	int random = std::rand() % 3;
	switch (random)
	{
	case 0:
		return new A;
	case 1:
		return new B;
	case 2:
		return new C;
	default:
		return nullptr;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

void identify(Base& p)
{
	// catch (...) because std::bad_cast lives in <typeinfo>, which is forbidden
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}
	catch (...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}
	catch (...) {}
	std::cout << "Unknown type" << std::endl;
}

int main(void){
	
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	Base* basePtr = generate();
	if (basePtr)
	{
		std::cout << "Identifying by pointer: ";
		identify(basePtr);
		std::cout << "Identifying by reference: ";
		identify(*basePtr);
		delete basePtr;
	}
	else
	{
		std::cerr << "Failed to generate a Base object." << std::endl;
	}
	return 0;
}