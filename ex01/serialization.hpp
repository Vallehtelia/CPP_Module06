
#pragma once

#include <iostream>
#include <cstdint>
#include "data.hpp"

#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Serialization
{
	private:
		Serialization();
		~Serialization();
		Serialization(const Serialization& other);
		Serialization& operator=(const Serialization& other);
    public:
        static uintptr_t serialize(Data* data);
        static Data* deserialize(uintptr_t data);
};

