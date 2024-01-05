/*
* TOPIC:
*	- tuple
*	- structured bindings
*/

#include<iostream>
using namespace std;

auto func()
{
	tuple<int, double, string> tupVal(10, 34.4, "Hai");
	return tupVal;
}

// Overload operator '<<'
std::ostream &operator<<(std::ostream & out, tuple<int, double, string> tupVal)
{	
	out << std::get<0>(tupVal) << '\t' << std::get<1>(tupVal) << '\t' << std::get<2>(tupVal);
	return out;
}

int main()
{
	tuple<int, double, string> t1 = func();	
	cout << t1 << endl;	// need to overload '<<' operator for printing purpose
	cout << "size(int): " << sizeof(int) << " size(double): " << sizeof(double);
	cout << " size(string): " << sizeof(string) << " size(tuple): " << sizeof(t1) << endl;

	int a;
	double b;
	string c;
	std::tie(a, b, c) = t1;
	cout << "a: " << a << " b: " << b << " c: " << c << endl;

	int x;
	string y;
	std::tie(x, std::ignore, y) = t1;
	cout << "x: " << x << " y: " << y << endl;

	// Structured bindings.	supported from c++ 17 onwards
	auto [A, B, C] = func();
	cout << "A: " << A << " B: " << B << " C: " << C << endl;

	// Count of tuple
	cout << "Tuple count: " << std::tuple_size<decltype(t1)>::value << endl;

	return 0;
}