#include <iostream>
#include "fileManager.h"
#include "RandomNumbers.h"
#include "PersonalData.h"
#include "CarInfo.h"

using namespace std;

int main(){
    FileManager fileManager;
    RandomNumbers randomGenerator;
    PersonalData personalDataManager;
    CarInfo car;

    randomGenerator.initMatrix();
    randomGenerator.loadMatrix();

    personalDataManager.inputInformation();
    personalDataManager.loadInformation();
    
    car.inputCarInfo();
    car.loadCarInfo();

    return 0;
   
}