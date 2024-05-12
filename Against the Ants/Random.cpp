#include "Random.h"


int Random::GetRandomNumber(int min, int max) {
	return rand() % (max - min) + min;
}

double Random::GetRandomNumber(double min, double max) {
	int n = 1000;
	return (double)Random::GetRandomNumber((int)min * n, (int)max * n) / (double)n;
}
