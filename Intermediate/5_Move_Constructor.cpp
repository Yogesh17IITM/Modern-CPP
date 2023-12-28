#include<iostream>
using namespace std;

class myclass
{
	int* m_ptr = nullptr;

public:
	myclass(int iParam) : m_ptr(new int(iParam))
	{
		cout << "Default c'tor" << this << " " << m_ptr << endl;
	}

	~myclass()
	{
		cout << "D'tor" << endl;
		if (m_ptr)
		{
			delete m_ptr;
			m_ptr = nullptr;
		}
	}

	// Copy c'tor - deep copy required
	myclass(const myclass& obj) : m_ptr(new int(*obj.m_ptr)) // 'm_ptr' is not going to be shared.
	{
		cout << "Copy c'tor: Deep copying. " << this << " " << m_ptr << endl;
	}

	// Move c'tor - shallow copy required as we will use the move semantic to capture the 'rValue'
	myclass(myclass&& obj) noexcept : m_ptr(obj.m_ptr)
	{
		obj.m_ptr = nullptr;
		cout << "Move c'tor called. Shallow copying" << this << " " << m_ptr << endl;
	}
};

myclass Factory(int param)
{
	/*
	myclass temp(param);
	return temp;
	*/
	// For the above implementation, following 2 cases can happen.
	// 
	// Case A: When move c'tor is not implemented.
	//		Copy c'tor will be called and deep copying will happen.
	// 
	// Case B: When move c'tor is implemented.
	//		Move c'tor will be called/ The temp object will be copied to the 'rvalue' (shallow copy).
	//		Then, temp will be destroyed and the rvalue will be returned.
	
	return myclass(param);	// behaves as if "myclass obj(param);"
	// For the above implementation,
	// when move c'tor is not implmented or not,
	//		destruction doesn't happen in this scope (but happens outside scope).

}

int main()
{
	myclass obj(999);
	myclass objA = obj;	// Copy C'tor called (deep copying)

	// Notice here the 'm_ptr' of 'objA' and 'obj' will have different addresses due to deep copying.

	cout << "--------------" << endl;
	myclass objB = Factory(111);
	cout << "--------------" << endl;
	myclass objC = std::move(objB);	// Move c'tor called (shallow copying). Transferring the ownership.
	// Notice here the 'm_ptr' of 'objB' and 'objC' will have same address due to shallow copying.
	
	return 0;
}