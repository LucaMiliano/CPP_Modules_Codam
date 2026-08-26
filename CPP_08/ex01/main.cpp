#include "Span.hpp"
#include <ctime>
#include <array>

int main(void) {

	int i = 0;
	int max = 10000;
	int arr[max];
	Span spannender(10000);
	unsigned int random;
	srand(time(0));
	while ( i < max)
	{
		random = rand();
		arr[i] = random;
		i++;
	}
	try {
	spannender.addRange(&arr[0], &arr[i]);
	} catch (const std::out_of_range &e) {
		std::cout << "Caught exception: " << e.what() << std::endl;
		return(1);
	}
	std::cout << "Shortest span: " << spannender.shortestSpan() << std::endl;
	std::cout << "Longest span: " << spannender.longestSpan() << std::endl;

	// example from subject:

	// Span sp = Span(5); try {
	// sp.addNumber(4);
	// sp.addNumber(3);
	// sp.addNumber(17);
	// sp.addNumber(9);
	// sp.addNumber(11);
	// } catch (const std::out_of_range &e) {
	// 	std::cout << "Caught exception: " << e.what() << std::endl;
	// 	return(1);
	// }
	// std::cout << sp.shortestSpan() << std::endl;
	// std::cout << sp.longestSpan() << std::endl;
	// return 0;
}
