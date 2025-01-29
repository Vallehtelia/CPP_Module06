
#include "serialization.hpp"

int main()
{
    {
        std::cout << CYAN << "----Test 1----" << RESET << std::endl;
        Data data;
        data.number = 42;
        data.text = "Hello, World!";

        uintptr_t serializedData = Serialization::serialize(&data);
        Data* deserializedData = Serialization::deserialize(serializedData);

        if (deserializedData)
        {
            std::cout << "Data address: " << &data << std::endl;
            std::cout << "deserializedData: " << deserializedData << std::endl;
            std::cout << "serializedData: " << serializedData << std::endl;
            if (&data == deserializedData)
                std::cout << GREEN << "Data address and deserializedData are the same!" << RESET << std::endl;
            std::cout << "Number: " << deserializedData->number << std::endl;
            std::cout << "Text: " << deserializedData->text << std::endl;
        }
    }
    {
        std::cout << CYAN << "----Test2----" << RESET << std::endl;
        Data data;
        data.number = 0;
        data.text = "Goodbye, World!";

        uintptr_t serializedData = Serialization::serialize(&data);
        Data* deserializedData = Serialization::deserialize(serializedData);

        if (deserializedData)
        {
            std::cout << "Data address: " << &data << std::endl;
            std::cout << "deserializedData: " << deserializedData << std::endl;
            std::cout << "serializedData: " << serializedData << std::endl;
            if (&data == deserializedData)
                std::cout << GREEN << "Data address and deserializedData are the same!" << RESET << std::endl;
            std::cout << "Number: " << deserializedData->number << std::endl;
            std::cout << "Text: " << deserializedData->text << std::endl;
        }
    }
    {
        std::cout << CYAN << "----Test3----" << RESET << std::endl;
        Data data;

        uintptr_t serializedData = Serialization::serialize(&data);
        Data* deserializedData = Serialization::deserialize(serializedData);

        if (deserializedData)
        {
            std::cout << "Data address: " << &data << std::endl;
            std::cout << "deserializedData: " << deserializedData << std::endl;
            std::cout << "serializedData: " << serializedData << std::endl;
            if (&data == deserializedData)
                std::cout << GREEN << "Data address and deserializedData are the same!" << RESET << std::endl;
            std::cout << "Number: " << deserializedData->number << std::endl;
            std::cout << "Text: " << deserializedData->text << std::endl;
        }
    }
}
