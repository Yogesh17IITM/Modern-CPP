/*
* TOPIC:
*	- std::Variant datatype
*   - std::optional return type
*/
#include<iostream>
#include<variant>
#include<optional>

using namespace std;

class KPH   // Kilometer-per-hour
{
public:
    int Speed_in_KPH;
};

class MPH   // Miles-per-hour
{
public:
    double Speed_in_MPH;
};

optional<string> print(auto speed)  // return type is 'optional'
{
    string oStr;
    bool isSuccess = true;
    try
    {
        if (holds_alternative<KPH>(speed))
            cout << "KPH: " << std::get<KPH>(speed).Speed_in_KPH << endl;
        else if (holds_alternative<MPH>(speed))
            cout << "MPH: " << std::get<MPH>(speed).Speed_in_MPH << endl;
        else
            throw - 999;
    }
    catch (const int& e)
    {
        cout << "Exception: " << e << endl;
        isSuccess = false;
    }

    if (isSuccess)
        return "TRUE";
    else
        return {};  // if nothing is returned, the statement in 'value_or("<statement>")' will be printed
}

int main()
{
    variant<KPH, MPH, int> Speed;    // Variant works like 'Union' which can handle multiple datatypes.
                                // This can be used instead of function overloading.
                                // It can hold only one object at a time (in this case, either KPH or MPH)

    // Initializing with 'KPH' type
    Speed = KPH{ .Speed_in_KPH = 20 };
    cout << print(Speed).value_or("default") << " --> Status\n" << endl;

    // Re-Initializing with 'MPH' type
    Speed = MPH{ .Speed_in_MPH = 12.4274 };
    cout << print(Speed).value_or("default") << " --> Status\n" << endl;

    // Re-initializing with 'int' type
    Speed = 10;
    cout << print(Speed).value_or("default") << " --> Status\n" << endl;

    return 0;
}