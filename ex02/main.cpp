
#include "base.hpp"
#include "classes.hpp"

int main() {
    int aCount = 0;
    int bCount = 0;
    int cCount = 0;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < 100; i++) {
        Base* obj = generate();
        if (dynamic_cast<A*>(obj))
            aCount++;
        else if (dynamic_cast<B*>(obj))
            bCount++;
        else if (dynamic_cast<C*>(obj))
            cCount++;
        delete obj;
    }
    std::cout << "A count: " << aCount << std::endl;
    std::cout << "B count: " << bCount << std::endl;
    std::cout << "C count: " << cCount << std::endl;

    Base* obj = generate();
    identify(obj);
    identify(*obj);

    delete obj;
    return 0;
}