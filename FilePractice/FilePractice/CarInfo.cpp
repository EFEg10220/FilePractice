#include "CarInfo.h"

CarInfo::CarInfo(){
    mileage = 0;
    numOfDoors = 0;
    passengerCapacity = 0;
    price = 0.0;
    year = 0;
}

CarInfo::~CarInfo(){

}

void CarInfo::inputCarInfo(){
    int numCars;
    cout << "\nIngrese la informacion de los carros: " << endl;
    cout << "같같 Ingrese la cantidad de carros: 같같"; cin >> numCars;
    cin.ignore();

    string fileName = "carInfo.txt";
    string* lines = new string[numCars];
    ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }

    for (int i = 0; i < numCars; i++) {
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

        string line = brand + "," + model + "," + to_string(year) + "," + color + "," + vin + "," + 
        to_string(price) + "," + to_string(mileage) + "," + engineState + "," + 
        to_string(numOfDoors) + "," + transmission + "," + fuelType + "," + to_string(passengerCapacity);

        lines[i] = line;
    }

    fileManager.save(lines, numCars, fileName);

    cout << "\nDatos guardados en el archivo: " << fileName << endl;
    delete[] lines;
}

void CarInfo::loadCarInfo(){
    int numCars;
    string fileName = "carInfo.txt";
    ifstream inputFile(fileName);
    string* loadedLines = fileManager.load(fileName, numCars);

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    if (loadedLines) {
        cout << "Informacion de los carros cargado desde el archivo: " << fileName << endl;
     
        for (int i = 0; i < numCars; i++) {
            istringstream ss(loadedLines[i]);
            getline(ss, brand, ',');
            getline(ss, model, ',');
            ss >> year;
            ss.ignore();
            getline(ss, color, ',');
            getline(ss, vin, ',');
            ss >> price;
            ss.ignore();
            ss >> mileage;
            ss.ignore();
            getline(ss, engineState, ',');
            ss >> numOfDoors;
            ss.ignore();
            getline(ss, transmission, ',');
            getline(ss, fuelType, ',');
            ss >> passengerCapacity;
            ss.ignore();

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
    inputFile.close();
}