#include "FileManager.h"

FileManager::FileManager(){

}

FileManager::~FileManager(){

}

void FileManager::save(const string* vectorString, int text, const string& fileName){
	ofstream file(fileName);
    if (file.is_open()) {
        for (int i = 0; i < text; ++i) {
            file << vectorString[i] << endl;
        }
        file.close();
    }
    else {
        cerr << "No se pudo abrir el archivo para escritura: " << fileName << endl;
    }
}


string* FileManager::load(const string& fileName, int& text){
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        text = 0;

        while (getline(file, line)) {
            text++;
        }

        file.clear();
        file.seekg(0, ios::beg);

        string* loadedLines = new string[text];

        int i = 0;
        while (getline(file, line)) {
            loadedLines[i] = line;
            i++;
        }

        file.close();
        return loadedLines;
    }else {
        cerr << "No se pudo abrir el archivo para lectura: " << fileName << endl;
        text = 0;
        return nullptr;
    }
}
