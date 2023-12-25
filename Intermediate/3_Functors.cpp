/*
* TOPIC:
*	-	Functors
*	-	Third-party function call adaptation
*/
#include<iostream>
using namespace std;

// Some logging function
template<typename T>
void Debug_log(T someFunc)
{
	cout << "\n---- Function Started ----" << endl;
	someFunc(); // callback
	cout << "---- Function Ended ----\n" << endl;
}

// Actual function
void Process_A()
{
	cout << "Running Process_A" << endl;
}

// Now, lets say that "Debug_log()" is some 3rd party function -> which accepts only function with no parameter.
// Consider if we have a function which has some parameters, then how to call Debug_log()?
// There comes 'functor' -> class objects acts as functions or function pointers
void Process_B(string iStr)
{
	cout << "Running Process_B " << iStr << endl;
}

typedef void (*FPTR)(string);
class wrapperLog
{
	FPTR m_funcPtr;	// function pointer
	string m_str;	// argument
public:
	explicit wrapperLog(FPTR fp, string iStr) : m_funcPtr(fp), m_str(iStr) {}

	void operator()() // overloading '()' operator
	{
		m_funcPtr(m_str);
	}
};

int main()
{
	// Basic usage
	Debug_log(Process_A);
	// Debug_log(Process_B); --> This doesn't work as the function has args. To solve it, use 'functors'

	// Advanced usage (making our function compatible with 3rd party function call)
	wrapperLog objLog(Process_B, "Success");	
	Debug_log(objLog);	// now, Process_B function with params called successfully with help of 'functor'.

	return 0;
}