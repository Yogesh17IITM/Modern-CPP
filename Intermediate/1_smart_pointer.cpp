/* TOPIC:
*   - Smart pointer
*   - 'explict' default c'tor
*   - shared and uniq pointer replica
*   - deep copying 
*/

#include<iostream>
using namespace std;

class classA
{
public:
    classA() {
        cout << "classA C'tor called" << endl;
    }

    ~classA() {
        cout << "classA D'tor called" << endl;
    }

    void func() {
        cout << "classA::func()" << endl;
    }
};

// Smart pointer
template<typename T>
class smart
{
    T* m_ptr;
    int* m_count;

    // Prevent smart pointer to be created on heap 
    // (eg., smart<int> pSmart = new smart<int>() )
    static void* operator new(size_t size) = delete;
    static void operator delete(void* pv) = delete;
    static void* operator new[](size_t size) = delete;
    static void operator delete[](void* pv) = delete;

public:
    explicit smart(T* iPtr = nullptr) : m_ptr(iPtr), m_count(nullptr) 
    {
        if (m_ptr != nullptr)
        {
            m_count = new int(1);
        }
    }

    ~smart()
    {
        if (m_count)
        {
            (*m_count)--;
            if ((*m_count) == 0)
            {
                if (m_ptr)
                {
                    delete m_ptr;
                    m_ptr = nullptr;
                }
                delete m_count;
            }
        }        
    }

    // If we prevent the copying or ownership sharing,
    // then it will be the replica of 'uniq' pointer
    /*smart(const smart&) = delete;
    smart& operator=(const smart& iObj) = delete;*/
        
    // replica of "shared pointer" implementation
    smart(const smart& iObj) : m_ptr(iObj.m_ptr), m_count(iObj.m_count)
    {
        (*m_count)++;
    }

    // replica of shared pointer
    smart& operator=(const smart& iObj)
    {
        /* Why not the below code?
        this->m_ptr = iObj.m_ptr;
        this->m_count = iObj.m_count;
        (*m_count)++;

        Cannot delete the exiting 'this' pointer object which it holds.
        since calling ~smart() from here is not allowed.

        Instead it overwrites on the existing one -> causes memory leak.
       
        // Case A: smart<classA> sp3(nullptr);
        // Case B: smart<classA> sp3(sp1);
        // Case A and B behaves differently here. 
           i.e,)    d'tor call happens for case A but NOT for case B.
                    since 'sp3(sp1) -> count++ and again sp3 = sp2 -> count++
                    Count increases twice but no destruction happens for existing object.
        */

        // DEEP COPYING
        smart temp(iObj); // copy c'tor called. Here the count will be increased by 1.
        swap(this->m_ptr, temp.m_ptr);      // then swap the pointer ownerships
        swap(this->m_count, temp.m_count);
        // so, now after swapping, once the 'temp' object goes out of scope, 
        // then, the swapped 'this (old ones)' pointer objects will be carefully destroyed.

        return *this;   // temp will be deleted here.
    }

    // '->' pointer operator
    T* operator->()
    {
        return m_ptr;
    }

    // '*' deference operator
    T& operator*()
    {
        return *m_ptr;
    }

    explicit operator bool()
    {
        return (m_ptr != nullptr);
    }

    void reset(T* iPtr = nullptr)
    {
        delete this->m_ptr;
        this->m_ptr = iPtr;
    }
};

int main()
{
    classA* pMyclass = new classA();   // User has to responsibly 'delete' the object
    if (pMyclass)
    {
        pMyclass->func();
    }
    cout << "-----------------------------------------------" << endl;

    // smart<myclass> sp_myclass = new myclass; 
    // implcit conversion not allowed as we prevent it with 'explicit'

    smart<classA> sp1(new classA);
    if (sp1)
    {
        sp1->func();
    }
    cout << "-----------------------------------------------" << endl;

    smart<classA> sp2(sp1); // copy c'tor called
    if (sp2)
    {
        sp2->func();
    }
    cout << "-----------------------------------------------" << endl;

    smart<classA> sp3(sp1); // copy c'tor called
    sp3 = sp2;
    if (sp3)
    {
        sp3->func();
    }
    cout << "-----------------------------------------------" << endl;
    return 0;
}