#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int main()
{
    //variables
    int numBus{ 0 };
    int headway{ 0 };
    int travelTime[18] = { 0 };
    int busCap{ 65 };

    // creating csv file
    ofstream file("dataPassengers.csv");
    

    cout << "Enter number of buses: ";
    cin >> numBus;
    file << "Number of Buses:," << numBus << endl;

    cout << "Enter headway time: ";
    cin >> headway;
    file << "Headway time:," << headway << endl;

    cout << "Enter travel time for each in order: ";
    file << "Travel Time:,";
    for (int i = 0; i < 18; i++) {
        cin >> travelTime[i];
        file << travelTime[i] << ",";
    }
    file << endl;
    file << "Bus Cap:," << busCap;


}
