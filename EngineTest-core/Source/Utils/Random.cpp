#include "Random.h"
#include "Time.h"

namespace EngineTest { namespace Utils {

	Random::Random() : Random(0)
	{

	}
	Random::Random(uint64 seed)
	{
		SetSeed(seed);
	}
	Random::~Random()
	{

	}

	uint32 Random::NextU()
	{
		m_Seed = (m_Seed * (uint64)0x5DEECE66D + (uint64)0xB) & (((uint64)1 << 48) - 1);
		return (uint32)(m_Seed >> 16);
	}
	int32 Random::NextI()
	{
		return (int32)NextU();
	}
	float Random::NextF()
	{
		return (float)NextU() / (float)(uint32)-1;
	}

	void Random::SetSeed(uint64 seed)
	{
		m_Seed = seed;
	}
	uint64 Random::GetSeed()
	{
		return m_Seed;
	}
}}