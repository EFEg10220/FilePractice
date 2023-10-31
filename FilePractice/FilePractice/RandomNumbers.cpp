#include "RandomNumbers.h"
#include <stdlib.h>
#include <time.h>


RandomNumbers::RandomNumbers(){

}

RandomNumbers::~RandomNumbers(){

}

void RandomNumbers::initMatrix() {
    string fileName = "randomMatrix.txt";
    ofstream outputFile(fileName);

    srand(time(nullptr));

    int* matrix = new int[row * column];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            matrix[i * column + j] = rand() % 100;
        }
    }

    string line;
    for (int i = 0; i < row * column; i++) {
        line += to_string(matrix[i]) + " ";
    }

    string* lines = new string[1];
    lines[0] = line;

    fileManager.save( lines , 1, fileName);

    delete[] matrix;
    delete[] lines;
}

void RandomNumbers::loadMatrix(){
    int numberLines;

    string fileName = "randomMatrix.txt";
    ifstream inputFile(fileName);

    cout << "Matriz: " << endl;
    string* loadLine = fileManager.load(fileName, numberLines);

    istringstream iss(loadLine[0]);


    int* values = new int[row * column];

    for (int i = 0; i < row * column; i++) {
        if (!(iss >> values[i])) {
            cerr << "Error al leer los valores desde el archivo." << endl;
            delete[] values;
            delete[] loadLine;
            return;
        }
    }

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < column; j++) {
            cout << values[i * column + j] << " ";
        }
        cout << endl;
    }

    cout << "\nMatriz cargada desde el archivo: " << fileName << endl;
    delete[] values;
    delete[] loadLine;
}
