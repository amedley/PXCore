#include "Game.h"
#include "Singletons.h"

namespace EngineTest {

	Game::Game()
	{
	}
	void Game::Init()
	{
		Window* window = Singletons::GetWindow();
		m_Width = (float)window->GetWidth();
		m_Height = (float)window->GetHeight();

		m_Group2D = new Group2D();

		m_Layer2D = new Layer2D(Matrix4::Orthographic(-window->GetWidth() / 2.0, window->GetWidth() / 2.0, -window->GetHeight() / 2.0, window->GetHeight() / 2.0, 0.0, 5000.0));

		m_Random = new Random(0);

		for (int i = 0; i < 5000; i++)
		{
			Entity2D* entity = new Entity2D();
			entity->GetTransform().SetPosition(Vector3(m_Width * (m_Random->NextF() - 0.5f) * 0.8f, m_Height * (m_Random->NextF() - 0.5f) * 0.8f, 0.0f));
			entity->GetTransform().ChangeRotation(m_Random->NextF() * 360.0f);
			entity->GetTransform().SetSize(Vector2(16.0f, 16.0f));
			entity->GetColor().m_RGBA = Vector4(m_Random->NextF(), m_Random->NextF(), m_Random->NextF(), 1.0f);
			m_Group2D->AddChild(*entity);
		}

		m_Layer2D->AddChild(*m_Group2D);

		m_Ticks = 0;
		m_TimeSpent = 0.0;

		double time0 = TimeSinceEpoch();
		while (!Singletons::GetWindow()->IsClosed())
		{
			double timeBefore = TimeSinceEpoch();
			if ((double)m_Ticks > m_TimeSpent * 60.0)
			{
				std::this_thread::sleep_for(std::chrono::nanoseconds((int)((m_Ticks - m_TimeSpent * 60.0) / 60.0 * 1000000000.0)));
			}
			else if ((double)m_Ticks < m_TimeSpent * 60.0)
			{
				int ticks = (int)(m_TimeSpent * 60.0 - (double)m_Ticks);
				for (int i = 0; i < ticks; i++)
				{
					OnUpdate();
				}
			}
			OnUpdate();
			OnRender();

			LOG("%f", 0.0166667 / (TimeSinceEpoch() - timeBefore) * 60.0);
			if (m_Ticks % 60 == 0)
			{
			//LOG("%llu, %f", m_Ticks, (TimeSinceEpoch() - time0) * 60.0);
			}


			m_TimeSpent = TimeSinceEpoch() - time0;
		}
	}
	void Game::OnUpdate()
	{
		// First increment ticks so that any update function knows what tick the game is on
		m_Ticks++;

		m_Layer2D->OnUpdate(m_Ticks);
		m_Layer2D->GetCamera().GetTransform().ChangeRotation(0.1f);

	}
	void Game::OnRender()
	{
		Singletons::GetWindow()->Clear();

		m_Layer2D->OnRender();

		//2D Top down camera
		
		/*Window* window = Singletons::GetWindow();
		Matrix4 proj = Matrix4::Orthographic(-window->GetWidth() / 2.0f, window->GetWidth() / 2.0f, -window->GetHeight() / 2.0f, window->GetHeight() / 2.0f, 0.0f, 10000.0f);



		Matrix4 view = Matrix4::Translate(-m_Position);
		Matrix4 model = Matrix4::Simple2DTransform(Vector3(100.0f, 50.0f, 0.0f), Vector2(100.0f, 100.0f), m_Rot0);

		Matrix4 transform = proj * view * model;
		Vertex2D vertices0[]
		{
			Vector3(-1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f),
			Vector3(-1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 0.0f, 0.0f, 1.0f),
			Vector3(+1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 1.0f, 0.0f, 1.0f),
			Vector3(+1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 1.0f, 0.0f, 1.0f),
			Vector3(+1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 1.0f, 1.0f, 1.0f),
			Vector3(-1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
		m_Rot0 += 0.001f;
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices0), vertices0, GL_STATIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, 6);


		model = Matrix4::Simple2DTransform(m_Position, Vector2(32.0f, 32.0f), m_Rot1);
		transform = proj * view * model;
		Vertex2D vertices1[]
		{
			Vector3(-1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f),
			Vector3(-1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f),
			Vector3(+1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 1.0f, 1.0f, 1.0f),
			Vector3(+1.0f, +1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 1.0f, 1.0f, 1.0f),
			Vector3(+1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(1.0f, 1.0f, 1.0f, 1.0f),
			Vector3(-1.0f, -1.0f, +0.0f).Multiply(transform), Vector4(0.0f, 0.0f, 0.0f, 1.0f)
		};
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
		glDrawArrays(GL_TRIANGLES, 0, 6);*/

		Singletons::GetWindow()->OnUpdate();
	}

	Game::~Game()
	{

	}

	uint64 Game::GetTicks()
	{
		return m_Ticks;
	}
}