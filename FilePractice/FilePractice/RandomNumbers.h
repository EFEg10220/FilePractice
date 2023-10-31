#pragma once
#include "FileManager.h"

class RandomNumbers {
private:
	FileManager& fileManager;

public:
	RandomNumbers(FileManager& fileManager);
	~RandomNumbers();

	void initMatrix(int row, int column, const string& fileName);
	void loadMatrix(const string& fileName);
};