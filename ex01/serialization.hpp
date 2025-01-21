
#pragma once

#include <iostream>
#include "data.hpp"

#define GREEN "\033[32m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

class Serialization
{
    public:
        static uintptr_t serialize(Data* data);
        static Data* deserialize(uintptr_t data);
};

