/*
* TOPIC:
*	- Heap object creation using 'new' operator
*   - override the operator 'new' and 'delete'
*   - prohibiting the heap object creation
*   - prohibiting object copying
*/

#include<iostream>
using namespace std;

class myclass
{
    bool m_bisOnHeap = false;	// non-static initialization - c++ 11 onwards
    static bool gHeap;

public:
    myclass() : m_bisOnHeap(gHeap)
    {
        cout << "c'tor" << endl;
        gHeap = false;
    }

    ~myclass()
    {
        cout << "d'tor" << endl;
        // throw 1;	// Do not throw exception from d'tor. Program will crash.
    }
        
    /*  During object creation on heap, the following 'new' operator gets called first
        then followed by the c'tor
    */
    static void* operator new(size_t size)
    {
        cout << "operator new called" << endl;
        gHeap = true;
        return malloc(size);
    }

    /*  During object deletion on heap, the following 'delete' operator gets called only after d'tor call.
    */
    static void operator delete(void* pv)
    {
        cout << "operator delete called" << endl;
        free(pv);
    }

    void location()
    {
        if (m_bisOnHeap)
            cout << "Obj created on the heap" << endl;
        else
            cout << "obj NOT created on the heap" << endl;
    }

    
    //  To prevent object creation on the heap, the following can be added
    // 
    //  1) For single object
    /*
    static void * operator new(size_t size) = delete;
    static void operator delete(void* pv) = delete;
    */
    //
    //  2) For array of objects
    static void* operator new[](size_t size) = delete;
    static void operator delete[](void* pv) = delete;

    // Similarly, to prevent copying,
    myclass(const myclass& obj) = delete;
    myclass &operator=(const myclass& obj) = delete;
    
};

bool myclass::gHeap = false;

int main()
{
    myclass* pMyclass = nullptr;
    try
    {
        pMyclass = new myclass();
    }
    catch (const std::exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
    
    if (pMyclass)
    {
        // Check of the object is created on the heap
        pMyclass->location();
        delete pMyclass;
    }
    cout << "----------------------------------" << endl;
    myclass obj;
    obj.location();
    cout << "----------------------------------" << endl;

    // myclass* pArrObj = new myclass[5];   // doesn't allow as we have restricted/

    return 0;
}