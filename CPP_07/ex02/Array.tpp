#include "Array.hpp"

template <typename T>
Array<T>::Array() : data(NULL), n(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : data(new T[n]()), n(n) {}

template <typename T>
Array<T>::Array(Array const &other) : data(new T[other.n]()), n(other.n) {
	for (unsigned int i = 0; i < n; i++) {
		data[i] = other.data[i];
	}
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &other) {
	if (this != &other) {
		delete[] data;
		n = other.n;
		data = new T[n]();
		for (unsigned int i = 0; i < n; i++) {
			data[i] = other.data[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array() {
	delete[] data;
}

template <typename T>
T const &Array<T>::operator[](unsigned int index) const{
	if (index >= n) {
		throw std::exception();
	}
	return data[index];
}

template <typename T>
T &Array<T>::operator[](unsigned int index) {
	if (index >= n) {
		throw std::exception();
	}
	return data[index];
}

template <typename T>
unsigned int Array<T>::size() const {
	return n;
}