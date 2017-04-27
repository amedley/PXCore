#ifndef RANDOM_H
#define RANDOM_H

#include <random>
#include "../Math/Math.h"

namespace EngineTest { namespace Utils {

	class Random
	{
	public:
		Random();
		Random(uint64 seed);
		~Random();

		uint32 NextU();
		int32 NextI();
		float NextF();

		void SetSeed(uint64 seed);
		uint64 GetSeed();
	private:
		uint64 m_Seed;
	};

}}

#endif