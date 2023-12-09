/*
*	Topic:	Calling conventions
*	Types:
*       1) __cdecl
*       2) __stdcall
*       3) __fastcall
*       4) __thiscall
*/

/* Vendor - consumer program */

// Vendors
int func_1(int x, int y) {
    return (x + y);
}

int __cdecl func_2(int x, int y) {
    return (x + y);
}    // default calling convention in C/C++

int __stdcall func_3(int x, int y) {
    return (x + y);
}

// '__fastcall' --> directing compiler to use registers if available -> for fast performance.
// else use '__cdecl'
int __fastcall func_4(int x, int y) {
    return (x + y);
}

class Vendor
{
public:
    static int func_5(int x, int y) {
        return (x + y);
    }

    // '__thiscall' -> internally invoked. -> only for non-static member functions    
    int __thiscall func_6(int x, int y) {   
        return (x + y);
    } // only for C++
};


#include<iostream>
using namespace std;

int main()
{
    int ret = 0;
    // 'Caller' functions
    ret = func_1(1, 2);
    ret = func_2(1, 2);
    ret = func_3(1, 2);
    ret = func_4(1, 2);
    ret = Vendor::func_5(1, 2);

    Vendor objVendor;
    ret = objVendor.func_5(1, 2);
    ret = objVendor.func_6(1, 2);

    // Notice in the .asm file, all the stack are cleaned by the 'callee' itself (C++20 compiler)

    return 0;
}