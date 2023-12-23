/*
* TOPIC:
*	C++ exception handling and c++ c'tor and d'tor calls - behind the scenes explained.
*/
#include<iostream>
using namespace std;

class Myclass
{
public:
	Myclass() {
		cout << "Myclass()" << endl;
	}

	~Myclass() {
		cout << "~Myclass()" << endl;
	}

	Myclass(const Myclass& obj) {
		cout << "Myclass() Copy C'tor" << endl;
	}

	Myclass& operator=(const Myclass& obj) {
		cout << "Myclass() Copy C'tor" << endl;
		return *this;
	}

	void status()
	{
		cout << "Myclass::status()" << endl;
	}
};

void vendor(int randNumber)
{
	if (randNumber < 0)
		throw 100;
}

int main()
{
	try
	{
		Myclass obj;	// C'tor will be called
			
		//vendor(-1);	// Uncommenting this line, will catch the vendor exception
		throw obj;		// Copy C'tor will be called (value copied to exception table). Then, exception thrown
						// D'tor will be called for the 'exception vf table'
	}
	catch (int e)
	{
		cout << "Exception caught " << endl;
	}
	catch (Myclass excepObj)	// Copy C'tor called. Object will be copied from the exception table
	{
		excepObj.status();		// D'tor will be called.
	}

	// D'tor will be called for the "obj".

	return 0;
}