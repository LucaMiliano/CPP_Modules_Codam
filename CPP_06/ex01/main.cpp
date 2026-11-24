#include "Serializer.hpp"
#include <cstdint>
#include <iostream>

int main(void)
{
	Data d;
	d.value = 42;
	Data* original = &d;
	std::uintptr_t raw = Serializer::serialize(original);
	Data* result = Serializer::deserialize(raw);

	std::cout << "original: " << original << " (value " << original->value << ")" << std::endl;
	std::cout << "raw:      " << raw << std::endl;
	std::cout << "result:   " << result << " (value " << result->value << ")" << std::endl;
	if (result == original)
		std::cout << "Serialization and deserialization successful!" << std::endl;
	else
		std::cout << "Something went wrong!" << std::endl;
	return 0;
}
