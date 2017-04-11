#include "Singletons.h"

namespace EngineTest
{
	Singletons* Singletons::s_Singletons = nullptr;

	void Singletons::Construct()
	{
		s_Singletons = new Singletons();
		s_Singletons->EstablishSingletons();
	}
	void Singletons::Shutdown()
	{
		delete s_Singletons;
		s_Singletons = nullptr;
	}
	
	Singletons::Singletons()
	{
	}
	Singletons::~Singletons()
	{
		delete m_Machine;
		delete m_FileUtils;
		delete m_Window;
		delete m_Game;
	}
	void Singletons::EstablishSingletons()
	{
		m_Machine						= new Machine();
		m_FileUtils						= new FileUtils();
		m_Window						= new Window("EngineTest", 1280, 720);
		m_Game							= new Game();
	}
	
	Machine*						Singletons::GetMachine()							{ return Singletons::Get()->m_Machine; }
	FileUtils*						Singletons::GetFileUtils()							{ return Singletons::Get()->m_FileUtils; }
	Window*							Singletons::GetWindow()								{ return Singletons::Get()->m_Window; }
	Game*							Singletons::GetGame()								{ return Singletons::Get()->m_Game; }
}