
#include "serialization.hpp"

uintptr_t Serialization::serialize(Data* data)
{
    return reinterpret_cast<uintptr_t>(data);
}

Data* Serialization::deserialize(uintptr_t data)
{
    return reinterpret_cast<Data*>(data);
}