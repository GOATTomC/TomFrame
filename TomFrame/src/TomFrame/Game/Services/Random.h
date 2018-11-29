#pragma once
#include "../../Core.h"

namespace TomFrame
{
	namespace Static
	{
		class TOMFRAME_API Random
		{
			Random();
			~Random();

			/*returns a "Random" int between min(included) and max(excluded)*/
			static int GetRandom(int min, int max);
			/*returns a "Random" float between min(included) and max(excluded)*/
			static float GetRandom(float min, float max);
		};
	}
}