/*
 *	TOPIC:
 *		C'tor synthesization:
 *
 *	DISCUSSION:
 *		- There is misconception that default c'tor is always will be synthesized by the compiler which is NOT true.
 *		- It will be synthesized only when needed as shown in the examples below
 */
#include <iostream>
using namespace std;

// Case: A
class Base
{
public:
    Base() {} // prolog - construction happens here
};

class Derived : public Base
{
public:
    // Here the Derived class c'tor will be synthesized in order to call the Base class c'tor.
    // Refer the line in .asm file: ??0Derived@@QEAA@XZ				; Derived::Derived

    // Things to try:
    // Try keeping "Derived()" and comment out "Base()", check again.
    // Default Base() will not be created in this case. Verify from .asm file
};

// Case: B
class Composite
{
    Base objBase;

public:
    // Here the composite class c'tor will be synthesized in order to call the Base class c'tor.
    // Refer the line in .asm file: ??0Composite@@QEAA@XZ				; Composite::Composite
};

// Case: C
class ClassWithVirtualFunc
{
public:
    // C'tor will be synthesized inorder to set/map the vPtr to appropriate vTable.
    // Refer the line in .asm file: ??0ClassWithVirtualFunc@@QEAA@XZ		; ClassWithVirtualFunc::ClassWithVirtualFunc
    virtual void SomeFunc() {}
};

int main()
{
    Derived objDer;
    Composite objComp;
    ClassWithVirtualFunc objVirClass;
    return 0;
}