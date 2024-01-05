/*
* TOPIC:
*	- Type inference
*	- decltype
*/
#include<iostream>
using namespace std;

template<typename T1, typename T2>
constexpr auto Sum(T1 t1, T2 t2)->decltype(t1 + t2)		// called as trailing datatype deduction
{
	return (t1 + t2);	// datatype will be deduced from 't1+t2'
}

/*
* auto Sum(int par) -> double
* {
*	// Logic
* }
* 
* the above code is same as the below one:
* 
* double Sum(int par)
* {
*	// Logic
* }
*/

int main()
{
	int a = 5;
	double b = 4.5;
	cout << "Return type of Sum() is: " << typeid(Sum(a, b)).name() << "\n";

	auto c = Sum(a, b);

	static_assert(std::is_same<decltype(c), double>(), "Type mismatch");
	// static_assert(std::is_same<decltype(c), int>(), "Type mismatch");	// ERROR: due to type mismatch

	decltype(a+b) d = 100;	// Not an integer. It is double since it deduce from 'a+b'
	cout << "typeid of variable 'd' is: " << typeid(d).name() << "\n";

	return 0;
}