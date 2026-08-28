//============================================================================
// Name        : SensorLogBuffer.cpp
// Author      : Mansi Patil
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main() {
	 int n;

	    cout << "Enter number of readings: ";
	    cin >> n;

	    double temperature[100];

	    for (int i = 0; i < n; i++)
	    {
	        cout << "Enter temperature " << i + 1 << ": ";
	        cin >> temperature[i];
	    }

	    double minTemp = 1000;
	    double maxTemp = -1000;
	    double sum = 0;

	    int valid = 0;
	    int errors = 0;

	    cout << "\nValid readings : ";

	    for (int i = 0; i < n; i++)
	    {
	        if (temperature[i] < 0)
	        {
	            errors++;
	            continue;
	        }

	        cout << temperature[i] << " ";

	        if (temperature[i] < minTemp)
	            minTemp = temperature[i];

	        if (temperature[i] > maxTemp)
	            maxTemp = temperature[i];

	        sum = sum + temperature[i];
	        valid++;
	    }

	    // Find first critical reading
	    for (int i = 0; i < n; i++)
	    {
	        if (temperature[i] >= 45)
	        {
	            cout << "\nFirst CRITICAL : Index "
	                 << i << " -> " << temperature[i] << " C";
	            break;
	        }
	    }

	    double average = sum / valid;

	    cout << "\nSkipped (errors) : " << errors;
	    cout << "\nMin : " << minTemp << " C";
	    cout << "\nMax : " << maxTemp << " C";
	    cout << "\nAvg : " << average << " C";

	    return 0;
}
