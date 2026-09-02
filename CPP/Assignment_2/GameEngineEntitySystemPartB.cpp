//============================================================================
// Name        : GameEngineEntitySystemPartB.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

namespace Physics
{
    double clamp(double val, double min, double max)
    {
        if (val < min)
        {
            return min;
        }

        if (val > max)
        {
            return max;
        }

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        if (val < min)
        {
            return min;
        }

        if (val > max)
        {
            return max;
        }

        return val;
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}

int main()
{
    // Physics clamp
    double velocity = Physics::clamp(120.5, 0.0, 100.0);

    cout << "Physics Clamp: " << velocity << endl;

    // GameMath clamp
    int health = GameMath::clamp(120, 0, 100);

    cout << "GameMath Clamp: " << health << endl;

    // Physics lerp
    double physicsPosition = Physics::lerp(0.0, 100.0, 0.5);

    cout << "Physics Lerp: " << physicsPosition << endl;

    // GameMath lerp
    double uiPosition = GameMath::lerp(0.0, 500.0, 0.25);

    cout << "GameMath Lerp: " << uiPosition << endl;

    // Limited namespace scope
    {
        using namespace Physics;

        cout << "Using Physics namespace inside block: "
             << clamp(150.0, 0.0, 100.0)
             << endl;

        cout << "Physics Lerp inside block: "
             << lerp(0.0, 200.0, 0.5)
             << endl;
    }

    // Outside the block, we use the namespace explicitly again
    cout << "Physics Clamp outside block: "
         << Physics::clamp(80.0, 0.0, 100.0)
         << endl;

    return 0;
}
