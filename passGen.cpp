#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int const TAP = 0, CASH = 1; // for easier readability

int main(){
        //variables
        unsigned int seed{0};
        unsigned int duration{0};
        unsigned int totPass{0};
        double probability{0};

        // creating csv file
        ofstream file("dataPassengers.csv");
        file << "Time Start (seconds), Stop Number, Destination Number, Payment Method\n";
        

        // seeding
        cout << "Enter seed: ";
        cin >> seed;
        srand(seed);

        // duration
        cout << "Enter duration (in seconds): ";
        cin >> duration;

        // amount
        cout << "Enter target amt of passengers: ";
        cin >> totPass;

        // creating passengers
        probability = (double)totPass / (double)duration; // more like the average flow of passenger per second
        int r = floor(probability); // constant flow
        for(int i = 0; i < duration; i++){
                for(int j = 0; j < r; j++){ // for every constant flow, create a passenger
                        int start = rand()%18;
                        int end  = rand()%18;
                        file << i << "," << start << "," << ((start == end) ? (end+1)%18 : end) << "," << ((rand()%2 == TAP) ? "Tap" : "Cash") << endl;
                }
                if((double)rand() / RAND_MAX < probability-r){ // the remaining probability, example 3.5, 3 passengers for sure then 50% chance for another passenger
                        int start = rand()%18;
                        int end  = rand()%18;
                        file << i << "," << start << "," << ((start == end) ? (end+1)%18 : end) << "," << ((rand()%2 == TAP) ? "Tap" : "Cash") << endl; // (NOTE: might needa reroll until stard and end are not equal)
                } 
        }


        
}


