#include <iostream>

class Base
{
public:
    virtual void show()
    {
        std::cout << "Base::show()" << std::endl;
    }
    virtual ~Base() = default;
};

class Derived : public Base
{
public:
    void show() override
    {
        std::cout << "Derived::show()" << std::endl;
    }
};

int main()
{
    Base *b = new Derived();
    b->show();
    delete b;
    return 0;
}