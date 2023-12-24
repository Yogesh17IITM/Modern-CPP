/*
* TOPIC:
*   Order of initialization
*/

#include <iostream>
using namespace std;

class myclass
{
    int x, y, z;

public:
    myclass() : z(10), y(z), x(y) 
    {
        cout << "x: " << x << " y: " << y << " z: " << z << endl;
        // Here x and y will have some random value
        // This is because order of initilization happens based on the order of variables declared.
        // (i.e) It works as 'myclass() : x(y), y(z), z(10)'
    }
};

int main()
{
    myclass obj;
}