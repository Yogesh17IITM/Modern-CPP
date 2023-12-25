/*
* TOPIC:
*	-	Callback function
*	-	Template Method design pattern (Keeping common impl. in base and keeping only variations in derived)
*/

#include<iostream>
using namespace std;

template<typename T>
class Speed
{
public:
    void GetSpeed()	// Keeping the common logic in the base class
    {
        cout << "GetSpeed start..." << endl;
        ((T*)this)->CalcSpeed();	// Function Callback. Derived class should implement "CalcSpeed()"
        cout << "GetSpeed ended..." << endl;
    }
};

class MilesPerHr : public Speed<MilesPerHr>
{
public:
    void CalcSpeed()		// Keeping the specific details in the derived class
    {
        cout << "Calc. speed in MPH" << endl;
    }
};

class KilometersPerHr : public Speed<KilometersPerHr>
{
public:
    void CalcSpeed()
    {
        cout << "Calc. speed in KPH" << endl;
    }
};

int main()
{
    Speed<MilesPerHr>* pSpeed_in_Mph = new MilesPerHr();
    if (pSpeed_in_Mph)
        pSpeed_in_Mph->GetSpeed();

    Speed<KilometersPerHr>* pSpeed_in_Kph = new KilometersPerHr();
    if (pSpeed_in_Kph)
        pSpeed_in_Kph->GetSpeed();

    return 0;
}