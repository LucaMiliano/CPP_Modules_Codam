#include "Array.tpp"



int main()
{
	// 1. Default constructor: empty array
	Array<int> a1;
	std::cout << "a1.size() = " << a1.size() << std::endl;

	// 2. Constructor with n: array of default-initialized elements
	Array<int> a2(5);
	std::cout << "a2.size() = " << a2.size() << std::endl;
	for (unsigned int i = 0; i < a2.size(); i++)
		std::cout << "a2[" << i << "] = " << a2[i] << std::endl; // should print 0s

	// fill it
	for (unsigned int i = 0; i < a2.size(); i++)
		a2[i] = i * 10;

	// 3. Copy constructor: deep copy check
	Array<int> a3(a2);
	a3[0] = 999; // modify copy
	std::cout << "a2[0] = " << a2[0] << " (should still be 0)" << std::endl;
	std::cout << "a3[0] = " << a3[0] << " (should be 999)" << std::endl;

	// 4. Assignment operator: deep copy check
	Array<int> a4;
	a4 = a2;
	a4[1] = 777;
	std::cout << "a2[1] = " << a2[1] << " (should still be 10)" << std::endl;
	std::cout << "a4[1] = " << a4[1] << " (should be 777)" << std::endl;

	// 5. Self-assignment
	a4 = a4;
	std::cout << "a4[1] after self-assign = " << a4[1] << " (should still be 777)" << std::endl;

	// 6. Out-of-bounds access should throw
	try {
		std::cout << a2[100] << std::endl;
		std::cout << "ERROR: no exception" << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught exception as expected: " << e.what() << std::endl;
	}

	// 7. const correctness: operator[] must work on a const reference
	const Array<int> &constRef = a2;
	std::cout << "constRef[2] = " << constRef[2] << std::endl;
	try {
		std::cout << constRef[100] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught exception on const access: " << e.what() << std::endl;
	}

	// 8. Works with a non-primitive type too
	Array<std::string> strArr(3);
	strArr[0] = "hello";
	strArr[1] = "world";
	strArr[2] = "!";
	for (unsigned int i = 0; i < strArr.size(); i++)
		std::cout << strArr[i] << " ";
	std::cout << std::endl;

	// 9. Zero-size array
	Array<int> a5(0);
	std::cout << "a5.size() = " << a5.size() << std::endl;
	try {
		std::cout << a5[0] << std::endl;
	} catch (std::exception &e) {
		std::cout << "Caught exception on zero-size access: " << e.what() << std::endl;
	}

	return 0;
}