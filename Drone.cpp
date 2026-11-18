#include "Drone.h"
#include <string>

using namespace std;




        Drone::Drone(string modelName, double batteryLife){
            this->modelName = modelName;
            this->batteryLife = batteryLife;
        }

        string Drone::getModelName(){
            return modelName;
        }
        double Drone::getBatteryLife(){
             return batteryLife;
        }