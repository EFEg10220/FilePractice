#include "CarInfo.h"

CarInfo::CarInfo(){
    year = 0;
    price = 0.0;
    mileage = 0;
    numOfDoors = 0;
    passengerCapacity = 0;
}

CarInfo::~CarInfo(){

}

void CarInfo::inputCarInfo(){
    int numCars;
    cout << "\nIngrese la informacion de los carros: " << endl;
    cout << "같같 Ingrese la cantidad de carros 같같"; cin >> numCars;
    cin.ignore();

    string fileName = "carInfo.txt";
    string* lines = new string[numCars];

    for (int i = 0; i < numCars; ++i) {
        cout << "\nCarro #" << (i + 1) << endl;
        cout << "Marca: "; cin >> brand;
        cout << "Modelo: "; cin >> model;
        cout << "Anno: "; cin >> year;
        cout << "Color: "; cin >> color;
        cout << "VIN: "; cin >> vin;
        cout << "Precio: "; cin >> price;
        cout << "Kilometraje: "; cin >> mileage;
        cout << "Estado del motor: "; cin >> engineState;
        cout << "Numero de puertas: "; cin >> numOfDoors;
        cout << "Transmision: "; cin >> transmission;
        cout << "Tipo de combustible: "; cin >> fuelType;
        cout << "Capacidad de pasajeros: "; cin >> passengerCapacity;

        string line = brand + " " + model + " " + to_string(year) + " " + color + " " + vin + " " + 
        to_string(price) + " " + to_string(mileage) + " " + engineState + " " + 
        to_string(numOfDoors) + " " + transmission + " " + fuelType + " " + to_string(passengerCapacity);

        lines[i] = line;
    }

    fileManager.save(lines, numCars, fileName);

    cout << "\nDatos guardados en el archivo: " << fileName << endl;
    delete[] lines;
}

void CarInfo::loadCarInfo(){
    int numCars;
    string fileName = "carInfo.txt";
    string* loadedLines = fileManager.load(fileName, numCars);

    if (loadedLines) {
        cout << "Informacion de los carros cargado desde el archivo: " << fileName << endl;
        for (int i = 0; i < numCars; ++i) {
            istringstream iss(loadedLines[i]);
            iss >> brand >> model >> year >> color >> vin >> price >> mileage >> engineState >> 
            numOfDoors >> transmission >> fuelType >> passengerCapacity;

            cout << "\nCarro #" << (i + 1) << endl;
            cout << "Marca: " << brand << endl;
            cout << "Modelo: " << model << endl;
            cout << "Anno: " << year << endl;
            cout << "Color: " << color << endl;
            cout << "VIN: " << vin << endl;
            cout << "Precio: " << price << endl;
            cout << "Kilometraje: " << mileage << endl;
            cout << "Estado del motor: " << engineState << endl;
            cout << "Numero de puertas: " << numOfDoors << endl;
            cout << "Transmision: " << transmission << endl;
            cout << "Tipo de combustible: " << fuelType << endl;
            cout << "Capacidad de pasajeros: " << passengerCapacity << endl;
        }

        delete[] loadedLines;
    }
}
