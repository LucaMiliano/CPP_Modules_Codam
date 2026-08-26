#include "Span.hpp"

Span::Span(unsigned int maxSize) : _values(), _maxSize(maxSize), _size(0) {
	if (_maxSize == 0 || _maxSize == 1)
		throw std::invalid_argument("Span size cannot be zero");
}

Span::Span(const Span &other) : _values(), _maxSize(other._maxSize), _size(0) {
	for (unsigned int i = 0; i < other._size; ++i)
		addNumber(other._values[i]);
}

Span::~Span() {}

Span &Span::operator=(const Span &other) {
	if (this != &other) {
		_values.clear();
		_maxSize = other._maxSize;
		_size = 0;
		for (unsigned int i = 0; i < other._size; ++i)
			addNumber(other._values[i]);
	}
	return *this;
}

void Span::addNumber(int number) {
	if (_size >= _maxSize)
		throw std::out_of_range("Span is full");
	_size++;
	_values.push_back(number);
}

int Span::shortestSpan()
{
	if (_values.size() < 2)
		throw std::out_of_range("Not enough elements");

	std::vector<int> sorted(_values);
	std::sort(sorted.begin(), sorted.end());
	unsigned int smallest = sorted[1] - sorted[0];
	for (size_t i = 0; i < sorted.size(); i++)
	{
		unsigned int diff = sorted[i + 1] - sorted[i];
		if (diff < smallest)
			smallest = diff;
	}
	return smallest;
}

int Span::longestSpan()
{
	int small;
	int big;
	bubbleSort();
	small = _values.front();
	big = _values.back();
	return (big - small);
}

void Span::bubbleSort()
{
	bool swap = true;
	while(swap){
		swap = false;
		for (size_t i = 0; i < _values.size()-1; i++) {
			if (_values[i]>_values[i+1] ){
				_values[i] += _values[i+1];
				_values[i+1] = _values[i] - _values[i+1];
				_values[i] -=_values[i+1];
				swap = true;
			}
		}
	}
}


