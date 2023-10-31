#pragma once
#include "FileManager.h"

class PersonalData {
private:
    FileManager fileManager;
    string name;
    string lastName;
    int age;
    string gender;

public:
    PersonalData();
    ~PersonalData();

    void inputInformation();
    void loadInformation();
};
