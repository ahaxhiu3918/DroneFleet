#include <iostream>
#include <string>
#include "Drone.h"

using namespace std;

void printDrone(Drone d);

int main(){

    int numDrones = 0;

    cout<<"How many drone are in the fleet ?"<<endl;
    cin>> numDrones;
    cin.get(); // because after there is a getline !!!

    Drone** myDroneArray = new Drone*[numDrones]{};

    cout<<"Please insert the infomations for the "<<numDrones<<" Drones"<<endl;

    //----- get every drone dynamically

    for(int i = 0; i<numDrones;i++){

        string modelName;
        double battery;

        cout<<"for drone "<<i + 1<<" what is "<<endl;
        cout<<"his model's name :";
        getline(cin,modelName);
        cout<<"his battery Life : ";
        cin>>battery;
        cin.ignore();
        cout<<"battery :"<<battery<<endl;
        myDroneArray[i] = new Drone(modelName,battery);

    }

    //------- print every drone 
    cout<<"\nHere is your drone GRande FLeet"<<endl;

    for(int i = 0; i<numDrones;i++){
        cout<<"Drone "<<i<<" :";
        printDrone(*myDroneArray[i]);

    }

    //------- delete every drone

    for(int i = 0; i<numDrones;i++){
        
        delete myDroneArray[i];
        myDroneArray[i] = nullptr;

    }

    delete[] myDroneArray;
    myDroneArray = nullptr;

    /* 
    // to "delete" a vector on C++ :: https://www.techiedelight.com/delete-vector-free-memory-cpp/ 
    myDroneVector.erase(myDroneVector.begin(),myDroneVector.end());
    vector<Drone*>().swap(myDroneVector);
    */
    return 0;

}



void printDrone(Drone d){

    cout<<"Name :"<<d.getModelName()<<" Battery Life : "<<d.getBatteryLife()<<" %"<<endl;
}