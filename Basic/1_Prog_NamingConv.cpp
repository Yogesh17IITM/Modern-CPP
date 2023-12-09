/*
*	Topic:	Naming Convensions (name mangling)
*	Explanation:
*		1)	In CPP, name mangling is supported.
*			For example, in the below function,
*				'func_cpp' is created as "?func_cpp@@YAXXZ" and 
*				'func_cpp(int)' is created as "?func_cpp@@YAXH@Z"
* 
*		2)	In "C", name mangline is not supported.
*			For instance, thee function "func_c" is created as "func_c" only
* 
*	Note:
*		To check, one can do the following:
*		- Right Click on VS Solution > C/C++ > Output Files > Assembler Output --> Set Assembly with Source Code (/FAs)
*		- Then, run with Debug mode. Check the file: x<64/86 arch>/Debug/<filename>.ASM
*		- Search for string "func_cpp" and "func_c"
*/

#include<iostream>
using namespace std;

/*************** CPP FUNC *********************/
void func_cpp()
// internally it interprets as given below:
// "extern "C++" void func_C++()
{
	cout << "func_C++() \n";
}

void func_cpp(int) // function overloaded 
{
	cout << "func_C++(int) \n";
}
/*******************************************/

/***************** C FUNC *******************/
extern "C" void func_c()
{
	printf("Hello I am C %d", 1);
}
/*******************************************/

int main()
{
	func_cpp();
	func_c();
	return 0;
}