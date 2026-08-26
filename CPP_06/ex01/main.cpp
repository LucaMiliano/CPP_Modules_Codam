#include "Serializer.hpp"

int main(void)
{
	Data d;
	d.value = 42;
	Data* original = &d;
	uintptr_t raw = Serializer::serialize(original);
	Data* result = Serializer::deserialize(raw);
	if (result == original)
		std::cout << "Serialization and deserialization successful!" << std::endl;
	else
		std::cout << "Something went wrong!" << std::endl;
	return 0;
}