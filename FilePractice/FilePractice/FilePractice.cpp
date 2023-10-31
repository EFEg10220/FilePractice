#include <iostream>
#include "fileManager.h"
#include "RandomNumbers.h"
#include "PersonalData.h"
#include "CarInfo.h"

using namespace std;

int main(){
    FileManager fileManager;
    RandomNumbers randomGenerator(fileManager);
    PersonalData personalDataManager(fileManager);
    CarInfo car;

    string saveText[] = { "Dog", "Cat", "Country" };
    fileManager.save(saveText, 3, "random.txt");

    int numberLines;
    string* loadText = fileManager.load("random.txt", numberLines);

    for (int i = 0; i < numberLines; ++i) {
        cout << loadText[i] << endl;
    }

    delete[] loadText;

    const string fileName = "randomMatrix.txt";
    int row = 5;
    int column = 5;

    randomGenerator.initMatrix(row, column, fileName);
    randomGenerator.loadMatrix(fileName);

    personalDataManager.inputInformation();
    personalDataManager.loadInformation();
    
    car.inputCarInfo();
    car.loadCarInfo();

    return 0;
   
}