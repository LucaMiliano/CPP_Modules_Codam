#pragma once

#include <iostream>
#include <string>
#include <exception>

template <typename T>
class Array
{
	private:
		T *data;
		unsigned int n;

	public:
		Array();
		Array(unsigned int n);
		Array(Array const &other);
		Array &operator=(Array const &other);
		~Array();

		T &operator[](unsigned int index);
		T const &operator[](unsigned int index) const;
		unsigned int size() const;
};