#include "PersonalData.h"
#include <iostream>
#include <fstream>
#include <string>

PersonalData::PersonalData(FileManager& fileManager): fileManager(fileManager){

}

PersonalData::~PersonalData(){

}

void PersonalData::inputInformation(){
    int totalPeople;

    cout << "\n같같캧ngresar la informacion de las personas: 같같�";
    cout << "\nIngrese la cantidad de personas: "; cin >> totalPeople;
    cin.ignore();

    string fileName = "personalData.txt";
    ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }
    for (int i = 0; i < totalPeople; ++i) {
        string name, lastName, gender;
        int age;

        cout << "Ingrese el nombre de la persona " << (i + 1) << ": "; getline(cin, name);
        cout << "Ingrese el apellido de la persona " << (i + 1) << ": "; getline(cin, lastName);
        cout << "Ingrese la edad de la persona " << (i + 1) << ": "; cin >> age; 
        cin.ignore();
        cout << "Ingrese el genero de la persona " << (i + 1) << ": "; getline(cin, gender);
        outputFile << name << " " << lastName << " " << age << " " << gender << endl;
    }
    outputFile.close();
    
    cout << "\nDatos guardados en el archivo: " << fileName << endl;
}

void PersonalData::loadInformation(){
    string fileName = "personalData.txt";
    ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    cout << "Informacion de las personas cargada desde el archivo: " << fileName << endl;
    string line;

    while (getline(inputFile, line)) {
        string name, lastName, gender;
        int age;

        istringstream iss(line);
        iss >> name >> lastName >> age >> gender;

        cout << "\nNombre: " << name;
        cout << "\nApellido: " << lastName;
        cout << "\nEdad: " << age;
        cout << "\nGenero: " << gender << endl;
    }

    inputFile.close();
}
