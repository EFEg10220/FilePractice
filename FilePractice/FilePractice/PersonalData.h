#pragma once
#include "FileManager.h"

class PersonalData {
private:
    FileManager& fileManager;
public:
    PersonalData(FileManager& fileManager);
    ~PersonalData();

    void inputInformation();
    void loadInformation();
};
