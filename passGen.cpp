#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cmath>

using namespace std;

int const TAP = 0;
int const CASH = 1;

// struct Passenger{
//         int arrivTime;
//         int stopN;
//         int destSt;
//         int paymentT;
//         int id;
// };

int main(){
        //variables
        unsigned int seed{0};
        unsigned int duration{0};
        unsigned int totPass{0};
        double probability{0};
        // unsigned int id{0};

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
        cout << "Enter target amt of passengers";
        cin >> totPass;

        // creating passengers
        probability = (double)totPass / (double)duration;
        int r = floor(probability);
        for(int i = 0; i < duration; i++){
                for(int j = 0; j < r; j++){
                        int start = rand()%18;
                        int end  = rand()%18;
                        file << i << "," << start << "," << ((start == end) ? (end+1)%18 : end) << "," << ((rand()%2 == TAP) ? "Tap" : "Cash") << endl; // might needa reroll until not equal
                }
                if((double)rand() / RAND_MAX < probability-r){
                        int start = rand()%18;
                        int end  = rand()%18;
                        file << i << "," << start << "," << ((start == end) ? (end+1)%18 : end) << "," << ((rand()%2 == TAP) ? "Tap" : "Cash") << endl;
                } 
        }


        
}

