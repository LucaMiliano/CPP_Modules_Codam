#pragma once

#include <vector>
#include <cstddef>
#include <iostream>
#include <stdexcept>
#include <algorithm>

class Span {
	private:
		std::vector<int> _values;
		unsigned int _maxSize;
		unsigned int _size;

	public:
		Span(unsigned int maxSize);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);
		void addNumber(int number);
		int shortestSpan();
		int longestSpan();
		void bubbleSort();
		template <typename Iterator>
		void addRange(Iterator first, Iterator last)
		{
			unsigned int range = static_cast<unsigned int> (std::distance(first, last));
			if (range > _maxSize - _size)
				throw std::out_of_range("Range too big for span");
			_values.assign(first + _size, last + _size);
			_size += range;
		};
};
