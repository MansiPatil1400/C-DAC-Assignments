//============================================================================
// Name        : CalibrationPacketParser.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

bool parsePacket(const int* rawData, int size,
                 int** outMin, int** outMax)
{
    if (size <= 0)
    {
        return false;
    }

    // Start with first value
    *outMin = (int*)&rawData[0];
    *outMax = (int*)&rawData[0];

    // Find min and max
    for (int i = 1; i < size; i++)
    {
        if (rawData[i] < **outMin)
        {
            *outMin = (int*)&rawData[i];
        }

        if (rawData[i] > **outMax)
        {
            *outMax = (int*)&rawData[i];
        }
    }

    return true;
}


int main()
{
    int packet[] = {45, 12, 67, 8, 55, 31};

    int* minPtr = nullptr;
    int* maxPtr = nullptr;

    if (parsePacket(packet, 6, &minPtr, &maxPtr))
    {
        cout << "Calibration Min : " << *minPtr << endl;
        cout << "Calibration Max : " << *maxPtr << endl;
    }

    return 0;
}
