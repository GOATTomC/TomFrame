#include "Random.h"
#include <stdlib.h>
#include <time.h>    

int TomFrame::Static::Random::GetRandom(int min, int max)
{
	srand(time(nullptr));

	return rand() % max + min;
}

float TomFrame::Static::Random::GetRandom(float min, float max)
{
	srand(time(nullptr));

	return (rand() / RAND_MAX * max) + min;
}

