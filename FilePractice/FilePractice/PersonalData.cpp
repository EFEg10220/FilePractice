#include "PersonalData.h"
#include <iostream>
#include <fstream>
#include <string>

PersonalData::PersonalData(){
    age = 0;
}

PersonalData::~PersonalData(){

}

void PersonalData::inputInformation(){
    int totalPeople;

    cout << "\n같같캧ngresar la informacion de las personas: 같같�";
    cout << "\nIngrese la cantidad de personas: "; cin >> totalPeople;
    cin.ignore();

    string fileName = "personalData.txt";
    string* people = new string[totalPeople];
    ofstream outputFile(fileName);

    if (!outputFile.is_open()) {
        cerr << "No se pudo abrir el archivo para escritura." << endl;
        return;
    }

    for (int i = 0; i < totalPeople; ++i) {

        cout << "\nPersona #" << (i + 1) << endl;
        cout << "Ingrese el nombre de la persona: " ; cin >> name;
        cout << "Ingrese el apellido de la persona: " ; cin >> lastName;
        cout << "Ingrese la edad de la persona: " ; cin >> age; 
        cout << "Ingrese el genero de la persona: "; cin >> gender;

        string line = name + "," + lastName + "," + to_string(age) + "," + gender;

        people[i] = line;
    }

    fileManager.save(people, totalPeople, fileName);

    cout << "\nDatos guardados en el archivo: " << fileName << endl;
    delete[] people;
}

void PersonalData::loadInformation(){
    int totalPeople;
    string fileName = "personalData.txt";
    ifstream inputFile(fileName);
    string* loadPeople = fileManager.load(fileName, totalPeople);

    if (!inputFile.is_open()) {
        cerr << "No se pudo abrir el archivo para lectura." << endl;
        return;
    }

    if (loadPeople) {
        cout << "Informacion de las personas cargada desde el archivo: " << fileName << endl;
        
        for (int i = 0; i < totalPeople; i++) {
            istringstream ss(loadPeople[i]);
            getline(ss, name, ',');     
            getline(ss, lastName, ','); 
            ss >> age;                 
            ss.ignore();               
            getline(ss, gender);

            cout << "\nPersona #" << (i + 1) << endl;
            cout << "Nombre: " << name << endl;
            cout << "Apellido: " << lastName << endl;
            cout << "Edad: " << age << endl;
            cout << "Genero: " << gender << endl;
        }
        delete[] loadPeople;
    }
    //string line;

   /* while (getline(inputFile, line)) {
        string name, lastName, gender;
        int age;

        istringstream ss(line);
        getline(ss, name, ',');
        getline(ss, lastName, ',');
        ss >> age;
        ss.ignore();
        getline(ss, gender);

        cout << "\nNombre: " << name;
        cout << "\nApellido: " << lastName;
        cout << "\nEdad: " << age;
        cout << "\nGenero: " << gender << endl;
    }*/
    
    inputFile.close();
}
