#include "easyfind.hpp"
// #include <list>
// #include <vector>

int main(void) {
	int num = 12;
	int arr[5] = {2, 4, 8, 12, 16};
	std::vector<int> vec = {5, 6, 12, 7, 9};
	std::list<int> list = {12, 2, 3, 12, 4, 5};

	try {
		std::cout << "arr: " << *easyfind(arr, num) << " found!" << std::endl;
		std::cout << "vec: " << *easyfind(vec, num) << " found!" << std::endl;
		std::cout << "list: " << *easyfind(list, num) << " found!" << std::endl;
	}
	catch (const std::out_of_range &e) {
		(void)e;
		std::cout << "Something went wrong" << std::endl;
	}
	return 0;
}
