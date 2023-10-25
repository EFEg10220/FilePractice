#include <iostream>
#include "fileManager.h"

using namespace std;

int main(){
    FileManager fileManager;

    string saveText[] = { "Dog", "Cat", "Country" };
    fileManager.save(saveText, 3, "random.txt");

    int numberLines;
    string* loadText = fileManager.load("random.txt", numberLines);

    for (int i = 0; i < numberLines; ++i) {
        cout << loadText[i] << endl;
    }

    delete[] loadText;

    return 0;
   
}