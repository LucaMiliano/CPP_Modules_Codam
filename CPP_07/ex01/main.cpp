#include "iter.hpp"



int main(void) {
	int array[] = {1, 2, 3, 4, 5};
	size_t length = 5;

	std::cout << "Original array: " << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << std::endl;
	iter(array, length, add10);
	std::cout << "Array after iter: " << array[0] << " " << array[1] << " " << array[2] << " " << array[3] << " " << array[4] << std::endl;
	std::cout << "Printing array values using iter: " << std::endl;
	iter(array, length, printValue);
	return 0;
}
