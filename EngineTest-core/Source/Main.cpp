#include "Singletons.h"

int main()
{
	using namespace EngineTest;
	
	Singletons::Get()->Construct();

	return 0;
}