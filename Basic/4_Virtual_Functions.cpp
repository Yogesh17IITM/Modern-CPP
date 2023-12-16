/*
* TOPIC:    C++ Virtual Functions and Keywords
*/

#include<iostream>
using namespace std;

class Base
{
public:
    virtual void func()
    {
        cout << "Base::func()" << endl;
    };
};

class Derived : public Base
{
public:
    // 'Override' ensure that if it is really happens
    // 'Final' - to ensure override happens and 
    //  also we convey it is the final implementation in the inheritence.
    virtual void func() override
    {
        cout << "Derived::func()" << endl;
    };
};

/*
* Note:
*   - 'vTable' will be created separately for each class (i.e,) in this example, base and derived.
*   - check for the following keywords in the respective .asm file.
*       1) ; Base::`vftable'
*       2) ; Derived::`vftable'
*/
int main()
{
    Derived objDerived;
    cout << "size of Base: " << sizeof(Base) << " and size of Derived: " << sizeof(Derived) << "\n";
    // size will be equal to size of 'vPtr' pointer. 
    // Note: size of an empty class is 1 byte.

    objDerived.func();  // Derived class function will be called here.

    return 0;
}