/*
* TOPIC:
*	- Designated initializations
*   - List initialization
*/

#include<iostream>
using namespace std;

class MyClass
{
public:
    int m_a;
    string m_str;
};

class MyDerivedClass : public MyClass
{
public:
    double m_dervied;
};

int main()
{
    MyClass objBase{ .m_a = 10, .m_str = "Base" };	// designated initializer list
    cout << "m_a: " << objBase.m_a << "\tm_str: " << objBase.m_str << endl;

    // base class initalized by designated initializer list 
    // but derived class by non-designated initializer list
    MyDerivedClass D1{ {.m_a = 15, .m_str = "Derived D1"}, 0.15 };

    // List initialization
    MyDerivedClass D2{ {16, "Derived D2"}, 1.5 };
    MyDerivedClass D3{ 17, "Derived D3", 4.5 };

    cout << "[D1] m_a: " << D1.m_a << "\tm_str: " << D1.m_str << "\tm_derived: " << D1.m_dervied << endl;
    cout << "[D2] m_a: " << D2.m_a << "\tm_str: " << D2.m_str << "\tm_derived: " << D2.m_dervied << endl;
    cout << "[D3] m_a: " << D3.m_a << "\tm_str: " << D3.m_str << "\tm_derived: " << D3.m_dervied << endl;

    return 0;
}