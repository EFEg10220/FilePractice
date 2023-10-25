#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class FileManager {
private:
	
public:

	FileManager();
	~FileManager();

	void save(const string* vectorString, int text, const string& fileName);
	string* load(const string& fileName, int& text);

};