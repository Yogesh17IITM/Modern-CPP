/*
* TOPIC:
*	rvalue and object destruction
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

	Myclass & operator=(const Myclass& obj) {
		cout << "Myclass() Copy C'tor" << endl;
		return *this;
	}
};

// Function to instantiate instance for MyClass
Myclass Func()
{
	Myclass obj;	// MyClass() C'tor will be called
	return obj;		// Copy c'tor called -> MyClass() instance will be moved to the rvalue.
					// Then, from the rvalue, the instance gets copied to the returning object.
					// then D'tor will be called.
}

int main()
{
	Func();			// Myclass usage is completed hereitself. Hence d'tor will be called.

	// Uncomment the below line and comment out the above line.
	//Myclass obj = Func();		// In this case, D'tor usage can be there. 
								// Hence D'tor will be called just before return.

	cout << "-------------" << endl;
	return 0;
}