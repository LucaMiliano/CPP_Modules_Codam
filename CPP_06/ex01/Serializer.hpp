#pragma once

#include <cstdint>
#include <iostream>

struct Data
{
	int value;
};

class Serializer
{ 

	public:
		static std::uintptr_t serialize(Data* ptr);
		static Data* deserialize(std::uintptr_t raw);
		Serializer() = delete;
		Serializer(const Serializer &other) = delete;
		Serializer &operator=(const Serializer &other) = delete;
		~Serializer() = delete;
};