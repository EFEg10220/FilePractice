#pragma once
#include "FileManager.h"

class RandomNumbers {
private:
	FileManager fileManager;

	const int row = 5;
	const int column = 5;

public:
	RandomNumbers();
	~RandomNumbers();

	void initMatrix();
	void loadMatrix();
};