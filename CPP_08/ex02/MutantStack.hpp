#pragma once

#include <vector>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T> 
{
	public:
		MutantStack();
		MutantStack(const MutantStack &other);
		~MutantStack();
		MutantStack &operator=(const MutantStack &other);
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}
};

#include "MutantStack.tpp"
