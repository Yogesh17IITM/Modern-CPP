/*
* TOPIC:
*	- Variadic template function (template packing and unpacking)
*/

#include<iostream>
using namespace std;

// Below function should be implemented (MANDATORY) when variadic function is defined
void LOG()	
{
	cout << "\n";
}

// Variadic function
template<typename T1, typename ...T2>
void LOG(T1 param, T2 ...pack)	// template Pack
{
	cout << param << "\t";
	LOG(pack...);	// Unpacking. 
	// Note: In the last recursive call, there won't be any function arguments.
	// During that time, 'LOG()' will be called.
}

int main()
{
	LOG(10, 1, 1.5f, "Hello");	// Passing values of different datatypes
	LOG("Hai", 2.f, 'a');
	return 0;
}