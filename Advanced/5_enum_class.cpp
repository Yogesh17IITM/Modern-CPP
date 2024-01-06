/*
* TOPICS:
*   -   enum class
*   -   The 'using enum' directive
*/

#include<iostream>
using namespace std;

// Derived enum class from 'uint8_t' (RECOMMENDED)
// Since it allocates sizeof(int) by default which is huge.
// Instead, we can derive it from uint8_t, uint16_t etc based on requirements.
enum class Color : uint8_t
{
    GREEN,
    YELLOW,
    BLUE,
    NOCOLOR
};

int main()
{
    cout << "Size of enum: " << sizeof(Color) << endl;

    Color eColor = Color::NOCOLOR;
    switch (eColor)
    {
        using enum Color;	// Supported from C++ 20 onwards
    case GREEN: // Color::GREEN:
        break;
    case YELLOW:
        break;
    case BLUE:
        break;
    case NOCOLOR:
        break;
    default:
        break;
    }

    return 0;
}