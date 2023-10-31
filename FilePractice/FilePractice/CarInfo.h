#pragma once
#include "FileManager.h"

class CarInfo {
private:
    FileManager fileManager;

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
    
public:

	CarInfo();
	~CarInfo();

    void inputCarInfo();
    void loadCarInfo();
};