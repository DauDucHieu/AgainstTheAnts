#pragma once

#include "Constants.h"
#include "Ant.h"
#include <vector>
using namespace std;

class AntPooling {
private:
	static vector<Ant*> antPool;
public:
	static Ant* GetInstance(Constants::ANT_TYPE type);
};

