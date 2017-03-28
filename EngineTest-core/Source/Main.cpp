#include "Game.h"

int main()
{
	using namespace EngineTest;
	
	Game::Construct();
	Game::Get()->Init();

	return 0;
}