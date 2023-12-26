/*
* TOPIC:
*	- Class template specialization
*	- Constexpr -> used to make the code segment available at compile time.
*/
#include<iostream>
using namespace std;

template<typename T>
class Log
{
public:
    explicit Log(const T iMsg) {
        cout << "Your Message is: " << iMsg << endl;
    }
};

// Template specialization for pointer type
template<typename T>
class Log<T*>	// syntax: class [class-name]<specialization-type>
{
public:
    explicit Log(const T* iMsg)
    {
        cout << "Your Message is: " << iMsg << endl;
    }
};

template<int retCode>
class Result
{
public:
    Result()
    {
        cout << "Result is: " << retCode << endl;
    }
};

int Func()
{
    cout << "Func() called" << endl;
    return 1;
}

constexpr int SomeFunc()
{    
    return 999;
}

int main()
{
    Log<char> objLog('A');
    Log<char*> objLogPtr("Hello\0");

    const int retCodeA = 0;
    Result<retCodeA> objA;

    // Let us consider Func() as template type as it returns 'int' type.
    // Result<func()> objFunc;      // ERROR: Since Func() executes at run-time but template executes at run-time.
    // To fix this, we can use 'constexpr'
    Result<SomeFunc()> objB;

    return 0;
}