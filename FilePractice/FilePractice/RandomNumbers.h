#pragma once
#include "FileManager.h"

class RandomNumbers {
private:
	FileManager fileManager;

public:
	RandomNumbers();
	~RandomNumbers();

	void initMatrix();
	void loadMatrix();
};