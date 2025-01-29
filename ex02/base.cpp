
#include "base.hpp"
#include "classes.hpp"

Base::~Base() {}

Base    *generate(void)
{
    int random = rand() % 3;
    if (random == 0)
        return new A();
    else if (random == 1)
        return new B();
    else
        return new C();
}

void    identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "class A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "class B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "class C" << std::endl;
}

void    identify(Base& p)
{
    try
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "class A" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "class B" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "class C" << std::endl;
        return ;
    }
    catch(const std::exception& e)
    {
    }
    std::cout << "Unknown type" << std::endl;
}
