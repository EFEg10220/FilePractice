#pragma once
#include "FileManager.h"

class CarInfo {
private:
    string brand;
    string model;
    int year;
    string color;
    string vin;
    double price;
    int mileage;
    string engineState;
    int numOfDoors;
    string transmission;
    string fuelType;
    int passengerCapacity;

    FileManager fileManager;
    
public:

	CarInfo();
	~CarInfo();

    void inputCarInfo();
    void loadCarInfo();
};