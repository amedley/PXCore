#ifndef TIME_H
#define TIME_H

#include <chrono>

namespace EngineTest
{
	namespace Utils
	{
		using namespace std::chrono;

		inline double TimeSinceEpoch()
		{
			return (double)duration_cast<nanoseconds>(system_clock::now().time_since_epoch()).count() / 1000000000.0;
		}
	}
}

#endif