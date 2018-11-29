#include "Random.h"
#include <stdlib.h>

int TomFrame::Static::Random::GetRandom(int min, int max)
{
	return min + (rand()) / (RAND_MAX / (max - min));
}

float TomFrame::Static::Random::GetRandom(float min, float max)
{
	return min + (rand()) / (RAND_MAX / (max - min));
}

