#include "MutantStack.hpp"
#include <list>

int main(void) {

	std::cout << "std::list output: " << std::endl;

	std::list<int> rstack;
	rstack.push_back(5);
	rstack.push_back(17);
	std::cout << rstack.back() << std::endl;
	rstack.pop_back();
	std::cout << rstack.size() << std::endl;
	rstack.push_back(3);
	rstack.push_back(5);
	rstack.push_back(737);
	rstack.push_back(0);
	std::list<int>::iterator it = rstack.begin();
	std::list<int>::iterator ite = rstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Mutantstack output: " << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator mu_it = mstack.begin();
	MutantStack<int>::iterator mu_ite = mstack.end();
	++mu_it;
	--mu_it;
	while (mu_it != mu_ite)
	{
	std::cout << *mu_it << std::endl;
	++mu_it;
	}
	std::stack<int> s(mstack);
	return 0;
}
