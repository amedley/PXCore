#include "Singletons.h"

namespace EngineTest
{
	Singletons* Singletons::s_Singletons = NULL;

	void Singletons::Construct()
	{
		s_Singletons = new Singletons();
		s_Singletons->EstablishSingletons();
	}
	void Singletons::Shutdown()
	{
		DELETE(s_Singletons);
	}
	
	Singletons::Singletons()
	{
	}
	Singletons::~Singletons()
	{
		DELETE(m_Machine);
		DELETE(m_FileUtils);
		DELETE(m_Window);
		DELETE(m_ShaderFactory);
		DELETE(m_Game);
	}
	void Singletons::EstablishSingletons()
	{
		m_Machine						= new Machine();
		m_FileUtils						= new FileUtils();
		m_Window						= new Window("EngineTest", 1280, 720);
		m_ShaderFactory					= new ShaderFactory();
		m_Game							= new Game();


		m_Game->Init();
	}
	
	Machine*				Singletons::GetMachine()				{ return Singletons::Get()->m_Machine; }
	FileUtils*				Singletons::GetFileUtils()				{ return Singletons::Get()->m_FileUtils; }
	Window*					Singletons::GetWindow()					{ return Singletons::Get()->m_Window; }
	Game*					Singletons::GetGame()					{ return Singletons::Get()->m_Game; }
	ShaderFactory*			Singletons::GetShaderFactory()			{ return Singletons::Get()->m_ShaderFactory; }
}